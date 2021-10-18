import React from 'react';
import {Pie} from 'react-chartjs-2';


const data = {
        labels: ['New Patients', 'Old Patients', 'Appointment'],
        datasets:[
                {
                        label:'Number of Patients',
                        data:[40,30,20],
                         backgroundColor: [
                                'rgba(255, 99, 132, 0.2)',
                                'rgba(54, 162, 235, 0.2)',
                                'rgba(255, 206, 86, 0.2)',
                        ],
                        borderColor:[
                                'rgba(255, 99, 132, 1)',
                                'rgba(54, 162, 235, 1)',
                                'rgba(255, 206, 86, 1)',
                                ],
                                borderWidth: 1,
                                        },
                                ],
    };

//     const mystyle = {backgroundColor: "white", fontFamily: "Poppins, sans-serif", fontSize: "15px", lineHeight: "25.5px", textDecoration: "none solid rgba(00,0,0,0.87)", wordSpacing: "0", height: "129.455px", width: "258.773px", padding: "10px 24px 14px 24px", minHeight: "auto", maxHeight: "auto", position: "relative"}

const PChart = () =>(
       // styling
        
        <div>
                <div class="container" style={{backgroundColor:"white", marginTop: "10px", fontSize: "15px", lineHeight: "25.5px", textDecoration: "none solid rgba(0,0,0,0.87)",verticalAlign: "middle", paddingBottom:"11px",borderRadius:"10px"}}>
                        <div class="row">
                                <h3 style={{fontFamily:"Poppins, sans-serif", fontSize:"20px", fontWeight: "600", lineHeight: "40px", textDecoration:": none solid rgb(58, 64, 91)"}}>Pie Representation</h3>
                        </div>
                        <div class="row" >
                                <Pie data={data} options={{responsive: true, maintainAspectRatio: false }}/>
                        </div>
    
                </div>
         </div>
);

export default PChart;