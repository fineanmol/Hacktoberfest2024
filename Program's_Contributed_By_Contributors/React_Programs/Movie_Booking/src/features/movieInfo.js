import {createSlice } from "@reduxjs/toolkit";

const initialStateValue = {name:"",language:"",ganres:[],premiered:"",officialSite:"",rating:{},network:{},image:{},summary:""}
export const movieInfoSlice = createSlice({
    name : "movieInfo",
    initialState :{value:initialStateValue},
    reducers:{
        currentMovie:(state,action)=>{
            state.value=action.payload
        },
        resetState:(state)=>{
            state.value=initialStateValue
        }
    }
})

export const {currentMovie,resetState}= movieInfoSlice.actions
export default movieInfoSlice.reducer