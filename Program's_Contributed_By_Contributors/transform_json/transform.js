const input = [
    {
        zip: '501',
        city: 'Holtsville',
        state_id: 'NY',
        state_name: 'New York',
        county_name: 'Suffolk'
    },
    {
        zip: '544',
        city: 'Holtsville',
        state_id: 'NY',
        state_name: 'New York',
        county_name: 'Suffolk'
    },
    {
        zip: '601',
        city: 'Adjuntas',
        state_id: 'PR',
        state_name: 'Puerto Rico',
        county_name: 'Adjuntas'
    },
    {
        zip: '602',
        city: 'Aguada',
        state_id: 'PR',
        state_name: 'Puerto Rico',
        county_name: 'Aguada'
    },
]

const output = {
    "Suffolk, New York (county)": {
        "type": "county",
        "zipcode": [
            "00501",
            "00544",
            "06390",
            "11701",
            "11702",
            "11703",
            "11704",
            "11705",
            "11706"
        ]
    },
    "New York (state)": {
        "type": "state",
        "zipcode": [
            "00501",
            "00544",
            "06390",
            "10001",
            "10002",
            "10003",
            "10004",
            "10005",
            "10006",
        ]
    }
}


const transformedData1 = {};
const transformedData2 = {};


const countyToZipcodeMapping = {};

const stateToZipcodeMapping = {};

input.forEach(item => {
    const { zip, county_name, state_name } = item;

    if (!countyToZipcodeMapping[county_name]) {
        countyToZipcodeMapping[county_name] = {
            type: 'county',
            zipcode: []
        };
    }

    countyToZipcodeMapping[county_name].zipcode.push(zip);

    if (!stateToZipcodeMapping[state_name]) {
        stateToZipcodeMapping[state_name] = {
            type: 'state',
            zipcode: []
        };
    }

    stateToZipcodeMapping[state_name].zipcode.push(zip);
});

// console.log(countyToZipcodeMapping);

// console.log(stateToZipcodeMapping);

const final = { ...countyToZipcodeMapping, ...stateToZipcodeMapping };
console.log(final)

//code for hacktoberfest2023
