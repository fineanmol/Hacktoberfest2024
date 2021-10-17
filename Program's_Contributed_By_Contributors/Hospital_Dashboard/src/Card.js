import React from 'react';
import './Card.css';

const Card = ({title="Title", total="Total Patients", description="Enter Description"}) =>(
    <div class="col-md-3">
            <div class="row">
                <h4>{title}</h4>
            </div>
            <div class="row">
                <p>{total}</p>
            </div>
            <div class="row">
                <span><h6>{description}</h6></span>  
            </div>
    </div>
);


// const Card = ()=>{
//     return (
//         <div class="col-md-3">
//             <div class="row">
//                 <h4>Appointments</h4>
//             </div>
//             <div class="row">
//                 <p>450</p>
//             </div>
//             <div class="row">
//                 <span><p>10%</p> <h6>Since last month</h6></span>  
//             </div>
            
            
//         </div>
//     );
// }

export default Card;