// trafficByApiSummarizer.js
// ------------------------------------------------------------------
//
// created: Tue Aug  7 14:42:00 2018
// last saved: <2021-March-23 16:19:35>
//

/* jshint esversion: 9, node: true, strict: implied */
/* global process, console, Buffer */

const apigeejs     = require('apigee-edge-js'),
      common       = apigeejs.utility,
      apigee       = apigeejs.apigee,
      sprintf      = require('sprintf-js').sprintf,
      opn          = require('opn'),
      {google}     = require('googleapis'),
      fs           = require('fs'),
      path         = require('path'),
      Getopt       = require('node-getopt'),
      readline     = require('readline'),
      async        = require('async'),
      netrc        = require('netrc')(),
      moment       = require('moment'),
      Interval     = require('./interval.js'),
      version      = '20210323-1426',
      GOOG_APIS_SCOPES = ['https://www.googleapis.com/auth/spreadsheets'],
      defaults     = {
        dirs : {
          cache : 'cache',
          output : 'output'
        },
        mgmtServer: 'https://api.enterprise.apigee.com'
      },
      getopt = new Getopt(common.commonOptions.concat([
        ['P' , 'prior', 'optional. use the prior (N-1) year or month. Default: the current year/month.'],
        ['d' , 'daily', 'optional. collect daily data for the period. Default: collect monthly data.'],
        ['S' , 'sheet', 'optional. create a Google Sheet with the data. Default: emit .csv file.'],
        [''  , 'start=ARG', 'optional. starting date in YYYYMMDD or YYYYMM format. Supercedes -P.'],
        ['' , 'nocache', 'optional. do not use cached data; retrieve from stats API']
      ])).bindHelp();

function handleError(e) {
  if (e) {
    common.logWrite('Error: ' + JSON.stringify(e, null, 2));
    process.exit(1);
  }
}

function readCachedFile(url, uniquifier) {
  if (options.nocache) { return false; }
  let today = moment(new Date()).format('YYYYMMDD'),
      cacheFileName = path.join(defaults.dirs.cache, uniquifier + '--' + today + '.json');
  if (opt.options.verbose) {
    common.logWrite('checking for cache file %s....', cacheFileName);
  }
  if (fs.existsSync(cacheFileName)) {
    if (opt.options.verbose) {
      common.logWrite('using cached data...');
    }
    return { data: fs.readFileSync(cacheFileName,'utf8') };
  }
  if (opt.options.verbose) {
    common.logWrite('no cached data available.');
  }
  return { cachefile: cacheFileName };
}

function retrieveData(org, options, cb) {
  options.cacheCheck = readCachedFile;
  org.stats.get(options, (error, response) => {
    handleError(error);
    if (response.data) {
      if (response.cachefile) {
        if (!fs.existsSync(defaults.dirs.cache)){
          fs.mkdirSync(defaults.dirs.cache);
        }
        fs.writeFileSync(response.cachefile, JSON.stringify(response.data));
      }
      return cb(null, response.data);
    }
  });
}

function handleOneTimeUnit(dataTable, dimension) {
  return record => {
    let thisMoment = moment(record.timestamp).add(1, interval.timeUnit).endOf(interval.timeUnit);
    let volume = parseFloat(record.value);
    if (opt.options.verbose) {
      console.log(sprintf('%-48s %-14s %f',
                          dimension.name,
                          thisMoment.format('YYYY-MM-DD'),
                          volume ));
    }
    if ( ! dataTable[dimension.name]) {
      dataTable[dimension.name] = interval.getRowOfZeros();
    }
    let col = interval.getColumnNumber(thisMoment);
    dataTable[dimension.name][col] = volume;
  };
}

function processJsonAnalyticsData(results) {
  let dataTable = {};
  if (results.environments[0].dimensions) {
    results.environments[0].dimensions.forEach(function(dimension){
      // dimension.name => api name
      var messageCounts = dimension.metrics[0];
      //console.log('found %d values', messageCounts.values.length);
      messageCounts.values.forEach(handleOneTimeUnit(dataTable, dimension));
    });
  }
  return dataTable;
}

function getDataForOneEnvironment(org, options){
  return function(environment, callback) {
    options.environment = environment;
    retrieveData(org, options, function(e, results){
      handleError(e);
      callback(null, { environment: environment, data : processJsonAnalyticsData(results) });
    });
  };
}

function sleep (time) {
  return new Promise(resolve => setTimeout(resolve, time));
}

function getNewGsuiteToken(oAuth2Client, tokenStashPath, callback) {
  console.log('\nYou must authorize API Traffic Summarizer to create a new sheet.\n');
  console.log('This script will now open a browser tab. After granting consent, you will');
  console.log('receive a one-time code. Return here and paste it in, to continue....\n');

  sleep(4200)
    .then(() => {
    const authUrl = oAuth2Client.generateAuthUrl({
            access_type: 'offline',
            scope: GOOG_APIS_SCOPES
          });
    // Authorize this app by visiting the url
    opn(authUrl, {wait: false});
    const rl = readline.createInterface({
            input: process.stdin,
            output: process.stdout
          });
    rl.question('Paste the one-time-code: ', code => {
      rl.close();
      oAuth2Client.getToken(code, (e, token) => {
        if (e) return callback(e);
        oAuth2Client.setCredentials(token);
        // Store the token to disk for later program executions
        fs.writeFile(tokenStashPath, JSON.stringify(token, null, 2) + '\n', (e) => {
          if (e) console.error(e); // this is a non-fatal condition
        });
        callback(oAuth2Client);
      });
    });
  });
}

/**
 * Create an OAuth2 client with the given credentials, and then execute the
 * given callback function.
 * @param {Object} credentials The authorization client credentials.
 * @param {function} callback The callback to call with the authorized client.
 */
function oauth2Authorize(credentials, callback) {
  const {client_secret, client_id, redirect_uris} = credentials.installed;
  const oAuth2Client = new google.auth.OAuth2(client_id, client_secret, redirect_uris[0]);
  const tokenStashPath = path.join(defaults.dirs.cache, ".gsheets_token_stash.json");

  // Check if there is a previously stashed token.
  fs.readFile(tokenStashPath, (e, token) => {
    if (e) return getNewGsuiteToken(oAuth2Client, tokenStashPath, callback);
    oAuth2Client.setCredentials(JSON.parse(token));
    callback(oAuth2Client);
  });
}

function summarizeEnvironments(rawlines) {
  var lines = [];
  //rawlines.forEach(x => { console.log(x); });
  rawlines.forEach((x1, i1) => {
    const org = x1[0];
    const env = x1[1];
    let line = lines.find( x => (x[0] == org) && (x[1] == env));

    if (line) {
      if (i1>0) {
        line.forEach( (val, column) => {
          if (column>1) {
            //console.log('line[%d] := %d + %d', column, line[column], x1[column + 1]);
            line[column] += x1[column + 1];
          }
        });
      }
    }
    else {
      line = [org, env].concat(x1.slice(3));
      lines.push(line);
    }
  });
  return lines;
}

function pushOneUpdate(sheets, spreadsheetId) {
  return function(item, cb) {
    // this is the format for .update()
    var options = {
            spreadsheetId: spreadsheetId,
            valueInputOption: 'USER_ENTERED',
            range: item.range,
            resource: {
              values: item.values
            }
        };
    sheets.spreadsheets.values.update(options, (e, updateResponse) => {
      handleError(e);
      cb(null, {});
    });
  };
}

function createSheet(label, lines) {
  return auth => {
    console.log('\nCreating a new spreadsheet on Google sheets...');
    const sheets = google.sheets({version: 'v4', auth});
    const today = moment(new Date()).format('YYYY-MMM-DD');
    const sheetTitles = [
            label,
            label.replace('api', 'environment')
          ];
    let request = {
          resource: {
            properties : {
              title: "API Traffic: " + opt.options.org + ' for ' + interval.getPeriod() + ' as of ' + today
            },
            sheets : [
              {
                properties: { sheetId : 0, title: sheetTitles[0] }
              },
              {
                properties: { sheetId : 1, title: sheetTitles[1] }
              }
            ]
          }
        };

    sheets.spreadsheets.create(request, function(e, createResponse) {
      // this function import raw data, adds sum formuli and pct, and produces charts.
      handleError(e);

      // from the raw data, aggregate the totals for the environments
      const lines2 = summarizeEnvironments(lines);

      // console.log('FiRST DATA LINE');
      //       console.log(JSON.stringify(lines[1]));
      //
      // console.log('SUMS');
      //
      // var obj = {
      //       range: sprintf("%s!R[%d]C[%d]:R[%d]C[%d]", sheetTitles[0], 1, lines[1].length , lines.length, lines[1].length ),
      //       // slice(1) skips the first row, which holds column headers, no values
      //       values: lines.slice(1).map((x, i) => [ sprintf('=SUM(indirect("R%dC4:R%dC%d",false))', i + 2, i + 2, x.length) ])
      //       // =SUM(indirect("R2C4:R2C22",false))
      //     };
      // console.log(JSON.stringify(obj, null, 2));

      // A single .batchUpdate() call failed with a HTTP 413 "Entity Too Large",
      // because the data is too large. To avoid that, this system makes N
      // requests in series.
      const updateData = [
              {
                // raw data
                range: sprintf("%s!R[0]C[0]:R[%d]C[%d]", sheetTitles[0], lines.length, lines[0].length + 1),
                values: lines.map(x => x.concat(['']) )
              },
              {
                // add a column that sums each row
                range: sprintf("%s!R[%d]C[%d]:R[%d]C[%d]", sheetTitles[0], 1, lines[1].length , lines.length, lines[1].length ),
                values: lines.slice(1).map((x, i) => [ sprintf('=SUM(indirect("R%dC4:R%dC%d",false))', i + 2, i + 2, x.length ) ])
              },
              {
                // add a row that sums each column
                range: sprintf("%s!R[%d]C[%d]:R[%d]C[%d]", sheetTitles[0], lines.length, 3, lines.length, lines[0].length),
                values: [lines[0].slice(3).map((v, i) => sprintf('=SUM(indirect("R2C%d:R%dC%d",false))', i + 4, lines.length, i + 4 ) )]
              },
              {
                // add a column that computes percentages for sheet0
                range: sprintf("%s!R[%d]C[%d]:R[%d]C[%d]", sheetTitles[0], 1, lines[0].length + 1, lines.length + 2, lines[0].length ),
                values: lines.map( (x, i) => [ sprintf('=indirect("R%dC%d",false)/indirect("R%dC%d",false)', i + 2, lines[0].length, lines.length + 1, lines[0].length) ] )
              },
              {
                // raw data summarized by environment
                range: sprintf("%s!R[0]C[0]:R[%d]C[%d]", sheetTitles[1], lines2.length, lines2[0].length + 1),
                values: lines2.map(x => x.concat(['']) )
              },
              {
                // add a column that sums each row
                range: sprintf("%s!R[%d]C[%d]:R[%d]C[%d]", sheetTitles[1], 1, lines2[1].length , lines2.length, lines2[1].length ),
                values: lines2.slice(1).map((x, i) => [ sprintf('=SUM(indirect("R%dC3:R%dC%d",false))', i + 2, i + 2, x.length ) ])
              },
              {
                // add a row that sums each column
                range: sprintf("%s!R[%d]C[%d]:R[%d]C[%d]", sheetTitles[1], lines2.length, 2, lines2.length, lines2[0].length),
                values: [lines2[0].slice(2).map((v, i) => sprintf('=SUM(indirect("R2C%d:R%dC%d",false))', i + 3, lines2.length, i + 3 ) )]
              },
              {
                // add a column that computes percentages for sheet1
                range: sprintf("%s!R[%d]C[%d]:R[%d]C[%d]", sheetTitles[1], 1, lines2[0].length , lines2.length + 1, lines2[0].length ),
                values: lines2.map( (x, i) => [ sprintf('=indirect("R%dC%d",false)/indirect("R%dC%d",false)', i + 2, lines2[0].length, lines2.length + 1, lines2[0].length) ] )
              }
            ];

      async.mapSeries(updateData,
                      pushOneUpdate(sheets, createResponse.data.spreadsheetId),
                      function(e, results) {
                        handleError(e);
                        // now, make a series of format changes, and add charts

                        var batchRequest = {
                              spreadsheetId: createResponse.data.spreadsheetId,
                              resource: {
                                requests: [

                                  {
                                    // format the numbers in sheet 0
                                    repeatCell: {
                                      range: {
                                        sheetId: 0,
                                        startRowIndex: 1,
                                        endRowIndex: lines.length + 1,
                                        startColumnIndex: 3,
                                        endColumnIndex: lines[0].length + 1
                                      },
                                      cell: {
                                        userEnteredFormat: {
                                          numberFormat: {
                                            type: "NUMBER",
                                            pattern: "#,##0"
                                          }
                                        }
                                      },
                                      fields: "userEnteredFormat.numberFormat"
                                    }
                                  },

                                  {
                                    // format the percentages in sheet 0
                                    repeatCell: {
                                      range: {
                                        sheetId: 0,
                                        startRowIndex: 1,
                                        endRowIndex: lines.length + 1,
                                        startColumnIndex: lines[0].length ,
                                        endColumnIndex: lines[0].length + 1
                                      },
                                      cell: {
                                        userEnteredFormat: {
                                          numberFormat: {
                                            type: "NUMBER",
                                            pattern: "0.00%"
                                          }
                                        }
                                      },
                                      fields: "userEnteredFormat.numberFormat"
                                    }
                                  },

                                  {
                                    // bold the sums in sheet 0
                                    repeatCell: {
                                      range: {
                                        sheetId: 0,
                                        startRowIndex: lines.length,
                                        endRowIndex: lines.length + 1,
                                        startColumnIndex: 3,
                                        endColumnIndex: lines[0].length
                                      },
                                      cell: {
                                        userEnteredFormat: {
                                          numberFormat: {
                                            type: "NUMBER",
                                            pattern: "#,##0"
                                          },
                                          textFormat: {
                                            bold: true
                                          }
                                        }
                                      },
                                      fields: "userEnteredFormat(numberFormat,textFormat)"
                                    }
                                  },

                                  {
                                    // freeze the header in sheet 0
                                    updateSheetProperties: {
                                      properties: {
                                        sheetId: 0,
                                        gridProperties: {
                                          frozenRowCount: 1
                                        }
                                      },
                                      fields: "gridProperties.frozenRowCount"
                                    }
                                  },

                                  {
                                    // format the header line in sheet 0
                                    repeatCell: {
                                      range: {
                                        sheetId: 0,
                                        startRowIndex: 0,
                                        endRowIndex: 1,
                                        startColumnIndex: 3,
                                        endColumnIndex: lines[0].length + 1
                                      },
                                      cell: {
                                        userEnteredFormat: {
                                          backgroundColor: {
                                            red: 0.0,
                                            green: 0.0,
                                            blue: 0.0
                                          },
                                          horizontalAlignment : "RIGHT",
                                          textFormat: {
                                            foregroundColor: {
                                              red: 1.0,
                                              green: 1.0,
                                              blue: 1.0
                                            },
                                            fontSize: 12,
                                            bold: true
                                          }
                                        }
                                      },
                                      fields: "userEnteredFormat(backgroundColor,textFormat,horizontalAlignment)"
                                    }
                                  },

                                  {
                                    // left justify the first three columns
                                    repeatCell: {
                                      range: {
                                        sheetId: 0,
                                        startRowIndex: 0,
                                        endRowIndex: 1,
                                        startColumnIndex: 0,
                                        endColumnIndex: 3
                                      },
                                      cell: {
                                        userEnteredFormat: {
                                          backgroundColor: {
                                            red: 0.0,
                                            green: 0.0,
                                            blue: 0.0
                                          },
                                          horizontalAlignment : "LEFT",
                                          textFormat: {
                                            foregroundColor: {
                                              red: 1.0,
                                              green: 1.0,
                                              blue: 1.0
                                            },
                                            fontSize: 12,
                                            bold: true
                                          }
                                        }
                                      },
                                      fields: "userEnteredFormat(backgroundColor,textFormat,horizontalAlignment)"
                                    }
                                  },

                                  {
                                    // resize all the columns
                                    autoResizeDimensions: {
                                      dimensions: {
                                        sheetId: 0,
                                        dimension: "COLUMNS",
                                        startIndex: 0,
                                        endIndex: lines[0].length + 1
                                      }
                                    }
                                  },

                                  {
                                    // format the numbers in sheet 1
                                    repeatCell: {
                                      range: {
                                        sheetId: 1,
                                        startRowIndex: 1,
                                        endRowIndex: lines2.length + 2,
                                        startColumnIndex: 2,
                                        endColumnIndex: lines2[0].length+1
                                      },
                                      cell: {
                                        userEnteredFormat: {
                                          numberFormat: {
                                            type: "NUMBER",
                                            pattern: "#,##0"
                                          }
                                        }
                                      },
                                      fields: "userEnteredFormat.numberFormat"
                                    }
                                  },

                                  {
                                    // format the percentages in sheet 1
                                    repeatCell: {
                                      range: {
                                        sheetId: 1,
                                        startRowIndex: 1,
                                        endRowIndex: lines2.length + 1,
                                        startColumnIndex: lines2[0].length ,
                                        endColumnIndex: lines2[0].length + 1
                                      },
                                      cell: {
                                        userEnteredFormat: {
                                          numberFormat: {
                                            type: "NUMBER",
                                            pattern: "0.00%"
                                          }
                                        }
                                      },
                                      fields: "userEnteredFormat.numberFormat"
                                    }
                                  },

                                  {
                                    // bold the sums in sheet 1
                                    repeatCell: {
                                      range: {
                                        sheetId: 1,
                                        startRowIndex: lines2.length,
                                        endRowIndex: lines2.length + 1,
                                        startColumnIndex: 2,
                                        endColumnIndex: lines2[0].length
                                      },
                                      cell: {
                                        userEnteredFormat: {
                                          numberFormat: {
                                            type: "NUMBER",
                                            pattern: "#,##0"
                                          },
                                          textFormat: {
                                            bold: true
                                          }
                                        }
                                      },
                                      fields: "userEnteredFormat(numberFormat,textFormat)"
                                    }
                                  },

                                  {
                                    // freeze the header in sheet 1
                                    updateSheetProperties: {
                                      properties: {
                                        sheetId: 1,
                                        gridProperties: {
                                          frozenRowCount: 1
                                        }
                                      },
                                      fields: "gridProperties.frozenRowCount"
                                    }
                                  },

                                  {
                                    // format the header in sheet 1
                                    repeatCell: {
                                      range: {
                                        sheetId: 1,
                                        startRowIndex: 0,
                                        endRowIndex: 1,
                                        startColumnIndex: 2,
                                        endColumnIndex: lines2[0].length + 1
                                      },
                                      cell: {
                                        userEnteredFormat: {
                                          backgroundColor: {
                                            red: 0.0,
                                            green: 0.0,
                                            blue: 0.0
                                          },
                                          horizontalAlignment : "RIGHT",
                                          textFormat: {
                                            foregroundColor: {
                                              red: 1.0,
                                              green: 1.0,
                                              blue: 1.0
                                            },
                                            fontSize: 12,
                                            bold: true
                                          }
                                        }
                                      },
                                      fields: "userEnteredFormat(backgroundColor,textFormat,horizontalAlignment)"
                                    }
                                  },

                                  {
                                    // left justify the first two columns
                                    repeatCell: {
                                      range: {
                                        sheetId: 1,
                                        startRowIndex: 0,
                                        endRowIndex: 1,
                                        startColumnIndex: 0,
                                        endColumnIndex: 2
                                      },
                                      cell: {
                                        userEnteredFormat: {
                                          backgroundColor: {
                                            red: 0.0,
                                            green: 0.0,
                                            blue: 0.0
                                          },
                                          horizontalAlignment : "LEFT",
                                          textFormat: {
                                            foregroundColor: {
                                              red: 1.0,
                                              green: 1.0,
                                              blue: 1.0
                                            },
                                            fontSize: 12,
                                            bold: true
                                          }
                                        }
                                      },
                                      fields: "userEnteredFormat(backgroundColor,textFormat,horizontalAlignment)"
                                    }
                                  },

                                  {
                                    // resize all the columns
                                    autoResizeDimensions: {
                                      dimensions: {
                                        sheetId: 1,
                                        dimension: "COLUMNS",
                                        startIndex: 0,
                                        endIndex: lines2[0].length + 1
                                      }
                                    }
                                  },

                                  {
                                    // add a chart.
                                    addChart: {
                                      chart: {
                                        spec: {
                                          title: "Requests",
                                          basicChart: {
                                            chartType: "LINE",
                                            legendPosition: "BOTTOM_LEGEND",
                                            axis: [
                                              {
                                                position: "LEFT_AXIS",
                                                title: "Requests"
                                              }
                                            ],
                                            // domains: [
                                            //   {
                                            //     domain: {
                                            //       sourceRange: {
                                            //         sources: [
                                            //           {
                                            //             sheetId: 0,
                                            //             startRowIndex: 0,
                                            //             endRowIndex: 1,
                                            //             startColumnIndex: 1,
                                            //             endColumnIndex:  lines[0].length + 1
                                            //           }
                                            //         ]
                                            //       }
                                            //     }
                                            //   }
                                            // ],
                                            series: Array(lines.length - 1).fill(0).map( (x, i) => {
                                              return {
                                                series: {
                                                  sourceRange: {
                                                    sources: [
                                                      {
                                                        sheetId: 0,
                                                        startRowIndex: i + 1,
                                                        endRowIndex: i + 2,
                                                        startColumnIndex: 2,
                                                        endColumnIndex: lines[0].length - 1
                                                      }
                                                    ]
                                                  }
                                                },
                                                targetAxis: 'LEFT_AXIS'
                                              };
                                            }),
                                            headerCount: 0
                                          }
                                        },
                                        position: {
                                          newSheet: true
                                        }
                                      }
                                    }
                                  },

                                  // add a second chart.
                                  {
                                    addChart: {
                                      chart: {
                                        spec: {
                                          title: "Requests",
                                          basicChart: {
                                            chartType: "LINE",
                                            legendPosition: "BOTTOM_LEGEND",
                                            axis: [
                                              {
                                                position: "LEFT_AXIS",
                                                title: "Requests"
                                              }
                                            ],
                                            // domains: [
                                            //   {
                                            //     domain: {
                                            //       sourceRange: {
                                            //         sources: [
                                            //           {
                                            //             sheetId: 1,
                                            //             startRowIndex: 0,
                                            //             endRowIndex: 1,
                                            //             startColumnIndex: 1,
                                            //             endColumnIndex: lines2[0].length + 1
                                            //           }
                                            //         ]
                                            //       }
                                            //     }
                                            //   }
                                            // ],
                                            series: Array(lines2.length - 1).fill(0).map( (x, i) => {
                                              return {
                                                series: {
                                                  sourceRange: {
                                                    sources: [
                                                      {
                                                        sheetId: 1,
                                                        startRowIndex: i + 1,
                                                        endRowIndex: i + 2,
                                                        startColumnIndex: 1,
                                                        endColumnIndex: lines2[0].length - 1
                                                      }
                                                    ]
                                                  }
                                                },
                                                targetAxis: 'LEFT_AXIS'
                                              };
                                            }),

                                            headerCount: 1
                                          }
                                        },
                                        position: {
                                          newSheet: true
                                        }
                                      }
                                    }
                                  },

                                 ]
                               }
                            };

                        sheets.spreadsheets.batchUpdate(batchRequest, function(e, sheetUpdateResponse) {
                          handleError(e);
                          var sheetUrl = sprintf('https://docs.google.com/spreadsheets/d/%s/edit', createResponse.data.spreadsheetId);
                          console.log('sheet url: %s', sheetUrl);
                          opn(sheetUrl, {wait: false});
                        });
                      });
    });
  };
}

function emitCsvFile(label, lines) {
  if (!fs.existsSync(defaults.dirs.output)){
    fs.mkdirSync(defaults.dirs.output);
  }
  const thisMinute = moment(new Date()).format('YYYYMMDDHHmm');
  const outputFile = path.join(defaults.dirs.output, label + '--' + thisMinute + ".csv");
  console.log('writing CSV output to   %s', outputFile);
  const stream = fs.createWriteStream(outputFile, {flags:'w'});
  lines.forEach(line => stream.write(line.join(', ') + '\n'));
  stream.end();
}

function doneAllEnvironments(e, results) {
  handleError(e);

  if (opt.options.verbose){
    //console.log('all done');
    console.log(JSON.stringify(results));
  }

  // cells is an array of arrays. Each item is an array of values for columns
  // in that line. Start with the header line.
  //
  let cells = [ ["org", "env", "proxyname"].concat(interval.getPeriodColumnHeads()).concat(["Total"]) ];

  //const add = (a, b) => a + b;
  results.forEach(function(dataTable) {
   Object.keys(dataTable.data).sort().forEach(function(key) {
     const row = dataTable.data[key];
     //console.log('row: ' + JSON.stringify(row));
     //const sum = row.reduce(add); // alternatively, we could ask the sheet to do this...
     let line = [opt.options.org, dataTable.environment, key]
       .concat(row);
       //.concat([sum]);
     cells.push(line);
   });
  });

  const label = sprintf('by-api--%s-%s', opt.options.org, interval.getPeriod());
  if (opt.options.sheet) {
    const clientCredentialsFile = path.join(".", "gsheets_client_credentials.json");
    fs.readFile(clientCredentialsFile, (e, content) => {
      if (e) {
        console.log('Error loading client credentials file:', e);
        return;
      }
      oauth2Authorize(JSON.parse(content), createSheet(label, cells));
    });
  }
  else {
    emitCsvFile('traffic-' + label, cells);
  }
}

function getInterval(opt) {
  let now = new Date();
  if (opt.options.start) {
    // from a specified day (or month) until now
    return new Interval(opt.options.start,
                        new Date(now.getFullYear(), now.getMonth() + 1, 0),  // eom
                        opt.options.daily);
  }

  let n = (opt.options.prior) ? 1: 0;
  if (opt.options.daily) {
    // current or prior month
    return new Interval(new Date(now.getFullYear(), now.getMonth() - n, 1),
                        new Date(now.getFullYear(), now.getMonth() + 1 - n, 0),
                        true);
  }

  // current or prior year
  return new Interval(new Date(now.getFullYear() - n, 0, 1),
                      new Date(now.getFullYear() - n, 11, 31),
                      false);
}


// ========================================================================================
var opt = getopt.parse(process.argv.slice(2));
if (opt.options.verbose) {
  console.log(
  `Apigee Analytics Summarizer tool, version: ${version}\n` +
    `Node.js ${process.version}\n`);
  common.logWrite('start');
}

if ( ! opt.options.org) {
  common.logWrite('You must specify an organization');
  getopt.showHelp();
  process.exit(1);
}

if (! opt.options.mgmtServer) {
  opt.options.mgmtServer = defaults.mgmtServer;
  if (opt.options.verbose) {
    common.logWrite('using Apigee Admin API endpoint: ' + opt.options.mgmtServer);
  }
}

let interval = getInterval(opt);

if (opt.options.verbose) {
  common.logWrite('using chart period: ' + interval.getPeriod());
}

common.verifyCommonRequiredParameters(opt.options, getopt);

var options = {
      nocache: opt.nocache,
      prior: opt.prior,
      daily: opt.daily,
      sheet: opt.sheet,
      start: opt.start,
      ...common.optToOptions(opt)
    };

apigee.connect(options, function(e, org) {
  handleError(e);

  org.environments.get(function(e, environments) {
    handleError(e);
    let statsOptions = {
          nocache   : opt.options.nocache,
          dimension : 'apis',
          metric    : 'sum(message_count)',
          startTime : interval.start,
          endTime   : interval.end,
          timeUnit  : interval.timeUnit
        };

    async.mapSeries(environments.filter( e => e != 'portal'),
                    getDataForOneEnvironment(org, statsOptions),
                    doneAllEnvironments);
  });

});
