import React from 'react';


export const Worklist = () =>{
    const names= ["UI Perfection", "Mega Section", "Operation Theatre", "Books Appointments", "UI Perfection", "Mega Section", "Operation Theatre", "Books Appointments"];
    return (
        <div style={{backgroundColor: "white", height: "390px"}}>
            <h5 style={{fontSize:"14px",lineHeight:"24px",borderBottom:"1px dotted", padding:"0 0 10px 5px", fontFamily:"Poppins, sans-serif"}}>{names[0]}</h5>
            <h5 style={{fontSize:"14px",lineHeight:"24px",borderBottom:"1px dotted" ,padding:"0 0 10px 5px", fontFamily:"Poppins, sans-serif"}}>{names[1]}</h5>
            <h5 style={{fontSize:"14px",lineHeight:"24px",borderBottom:"1px dotted" ,padding:"0 0 10px 5px", fontFamily:"Poppins, sans-serif"}}>{names[3]}</h5>
            <h5 style={{fontSize:"14px",lineHeight:"24px",borderBottom:"1px dotted" ,padding:"0 0 10px 5px", fontFamily:"Poppins, sans-serif"}}>{names[2]}</h5>  
            <h5 style={{fontSize:"14px",lineHeight:"24px",borderBottom:"1px dotted" ,padding:"0 0 10px 5px", fontFamily:"Poppins, sans-serif"}}>{names[4]}</h5>
            <h5 style={{fontSize:"14px",lineHeight:"24px",borderBottom:"1px dotted" ,padding:"0 0 10px 5px", fontFamily:"Poppins, sans-serif"}}>{names[5]}</h5>
            <h5 style={{fontSize:"14px",lineHeight:"24px",borderBottom:"1px dotted" ,padding:"0 0 10px 5px", fontFamily:"Poppins, sans-serif"}}>{names[6]}</h5>
            <h5 style={{fontSize:"14px",lineHeight:"24px",borderBottom:"1px dotted" ,padding:"0 0 10px 5px", fontFamily:"Poppins, sans-serif"}}>{names[7]}</h5>
            <h5 style={{fontSize:"14px",lineHeight:"24px",borderBottom:"1px dotted" ,padding:"0 0 10px 5px", fontFamily:"Poppins, sans-serif"}}>{names[0]}</h5>
        </div>
    );
}