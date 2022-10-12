import React, { useEffect, useState } from "react";
import { Line } from "react-chartjs-2";
import axios from "axios";
import Chart from "chart.js/auto";
import numeral from "numeral";
import { CategoryScale } from "chart.js";
import "./LineGraph.css";
import { FormControl, MenuItem, Select } from "@mui/material";

Chart.register(CategoryScale);

const options = {
  legend: {
    display: false,
  },
  elements: {
    point: {
      radius: 0,
    },
  },
  maintainAspectRatio: false,
  tooltips: {
    mode: "index",
    intersect: false,
    callbacks: {
      label: function (tooltipItem, data) {
        return numeral(tooltipItem.value).format("+0,0");
      },
    },
  },
  scales: {
    // x: [
    //   {
    //     type: "time",
    //     time: {
    //       format: "MM/DD/YY",
    //       tooltipFormat: "ll",
    //     },
    //   },
    // ],
    // x: {
    //   type: 'time',
    //   // time: {
    //   //   format: "MM/DD/YY",
    //   //   tooltipFormat: "ll",
    //   // },
    // },
    y: {
      // Include a dollar sign in the ticks
      ticks: {
        // Include a dollar sign in the ticks
        callback: function (value, index, values) {
          return numeral(value).format("0.0a");
        },
        stepSize: 5000,
      },
      beginAtZero: true,
    },
  },
};

const bulidChartData = (data, caseType = "cases") => {
  const chartData = [];
  let lastDataPoint;
  for (let date in data[caseType]) {
    // console.log(caseType,"=>",date,data[caseType]);
    if (lastDataPoint) {
      let yData;
      if (data[caseType][date] - lastDataPoint > 0)
        yData = data[caseType][date] - lastDataPoint;
      else yData = 0;
      const newData = {
        x: date,
        // x: new Date(date),
        y: yData,
      };
      chartData.push(newData);
    }
    lastDataPoint = data[caseType][date];
  }
  return chartData;
};

function LineGraph({ country, caseType = "cases" }) {
  const [data, setData] = useState({});

  useEffect(() => {
    let url,
      days = 120;
    if (caseType === "recovered") {
      days = 500;
    }
    url =
      country === "WorldWide"
        ? `https://disease.sh/v3/covid-19/historical/all?lastdays=${days}`
        : `https://disease.sh/v3/covid-19/historical/${country}?lastdays=${days}`;
    axios
      .get(url)
      .then((response) =>
        country === "WorldWide" ? response.data : response.data.timeline
      )
      .then((data) => {
        const chartData = bulidChartData(data, caseType);
        setData(chartData);
      });
  }, [caseType, country]);

  let backgroundColor="rgba(204, 16, 52, 0.5)",borderColor= "#CC1034";
  if(caseType==='recovered')
   {
     backgroundColor="rgb(125, 215, 29,0.5)";
     borderColor="#7dd71d";
   }
   else if (caseType==='deaths'){
    backgroundColor="rgb(251, 68, 67,0.5)";
    borderColor="#fb4443";
  }

  return (
    <div>
      {data?.length > 0 && (
        <Line
          className="LineGraph"
          options={options}
          data={{
            datasets: [
              {
                label: caseType,
                backgroundColor: `${backgroundColor}`,
                borderColor: `${borderColor}`,
                fill: true,
                data: data,
              },
            ],
          }}
        />
      )}
    </div>
  );
}

export default LineGraph;
