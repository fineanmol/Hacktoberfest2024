import React from 'react';
import {Bar} from 'react-chartjs-2';

// data for bar graph

const data = {
    labels: ['2000','2001','2002','2003','2004','2005'],
    datasets: [
        {
           label: 'Income'  ,
           data:[22,54,37,23,25.3,76],
           backgroundColor: 'rgb(255, 99, 132)'
        },
        {
            label:'Expenses',
            data :[35,45,47,10,35,70],
            backgroundColor: 'rgb(54, 162, 235)'
        }
    ]
};

const options = {
    scales: {
      yAxes: [
        {
          ticks: {
            beginAtZero: true,
          },
        },
      ],
    },
  };
  

const BChart = () =>(

    <div>
        <div class="container" style={{backgroundColor:"white", marginTop: "10px", fontSize: "15px", lineHeight: "25.5px", textDecoration: "none solid rgba(0,0,0,0.87)",verticalAlign: "middle",borderRadius:"10px"}}>
                <div class="row">
                    <h3 style={{fontFamily:"Poppins, sans-serif", fontSize:"20px", fontWeight: "600", lineHeight: "40px", textDecoration:": none solid rgb(58, 64, 91)"}}>Bar Representation</h3>
                </div>
                <div class="row">
                <Bar data={data} options={options}/>
                </div>
        
         </div>
    </div>

);



export default BChart;