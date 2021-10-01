import React from 'react';
import './App.css';

interface User{
  name: string,
  age: number,
  email: string
}
function App() {
  const user : User = {
    name: "John Doe",
    age: 30,
    email: "johndoe@gmail.com"
  }
  return (
    <div className="App">
      <div className="container">
      {
        user === null? "loading" : (
          <div className="details">
            <img src="https://encrypted-tbn0.gstatic.com/images?q=tbn:ANd9GcSNUGFZDrnAumJwM5JkKRRA0xCLvqmkzBFoT4fR33pL4YlwoE7yyEVB3GPgoM-QZIHRU7s&usqp=CAU" alt="" />
            <p>Name : {user.name}</p>
            <p>Age : {user.age}</p>
            <p>Email : {user.email}</p>
          </div>
        )
      }
      </div>
    </div>
  );
}

export default App;
