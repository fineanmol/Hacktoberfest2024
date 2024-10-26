import {v4 as uuidv4} from "uuid"
const GET_RAW_PATH="/getPerson";
const CREATE_RAW_PATH="/createPerson";

export const handler = async (event) => {
      // TODO implement
      console.log(event);
      if(event.rawPath==GET_RAW_PATH){
        console.log("Start Get");
        const personId=event.queryStringParameters.personId;
        console.log("Received person id", personId);
        const response = {
          statusCode: 200,
          body: JSON.stringify({
              name:"Anshika Dubey",
              email:"mygmail@gmail.com",
          }),
          headers: {
              "Content-Type": "application/json",
          },
        };
        return response
      }else if(event.rawPath==CREATE_RAW_PATH){
          console.log("Start Post");
          const data=JSON.parse(event.body);
          console.log("Name",data);
          return {"id":uuidv4()};
      }
};
