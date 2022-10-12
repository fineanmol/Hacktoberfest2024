import {
  Card,
  CardContent,
  FormControl,
  MenuItem,
  Select,
} from "@mui/material";
import axios from "axios";
import { useEffect, useState } from "react";
import "./App.css";
import InputBox from "./components/InputBox";
import LineGraph from "./components/LineGraph";
import Map from "./components/Map";
import Table from "./components/Table";
import { prettyPrintStat, sortData } from "./util";
import "leaflet/dist/leaflet.css";

function App() {
  const [countries, setCountries] = useState([]);
  const [country, setCountry] = useState("WorldWide");
  const [countryInfo, setCountryInfo] = useState({});
  const [tableData, setTableData] = useState([]);
  const [mapCenter, setMapCenter] = useState({ lat: 34.80746, lng: -40.4796 });
  const [mapZoom, setMapZoom] = useState(3);
  const [mapCountries, setMapCountries] = useState([]);
  const [casesType, setCasesType] = useState("cases");

  useEffect(() => {
    const loadCountries = async () => {
      const WorldWideResponse = await axios.get(
        "https://disease.sh/v3/covid-19/all"
      );
      const WorldWideData = WorldWideResponse.data;
      setCountryInfo(WorldWideData);
      const respone = await axios.get(
        "https://disease.sh/v3/covid-19/countries"
      );
      setMapCountries(respone.data);
      const sortedData = sortData(respone.data);
      setTableData(sortedData);
      const data = respone.data.map((country) => {
        return {
          name: country.country,
          value: country.countryInfo.iso2,
        };
      });
      setCountries(data);
    };
    loadCountries();
  }, []);

  const casesTypeChangeHandler = (event) => {
    setCasesType(event.target.value);
  };
  const countryChangeHandler = async (event) => {
    const countryCode = event.target.value;

    const url =
      countryCode === "WorldWide"
        ? "https://disease.sh​/v3​/covid-19​/all"
        : `https://disease.sh/v3/covid-19/countries/${countryCode}`;
    const response = await axios.get(url);
    const data = await response.data;
    setMapCenter({ lat: data.countryInfo.lat, lng: data.countryInfo.long });
    setMapZoom(4);
    setCountryInfo(data);
    setCountry(countryCode);
  };
  return (
    <div className="app">
      <div className="app__left">
        <div className="app__header">
          <h1>Covid19-Tracker</h1>
          <FormControl className="app__dropdown">
            <Select
              variant="outlined"
              value={country}
              onChange={countryChangeHandler}
            >
              <MenuItem value="WorldWide">WorldWide</MenuItem>
              {countries.map((country) => (
                <MenuItem key={country.value} value={country.value}>
                  {country.name}
                </MenuItem>
              ))}
            </Select>
          </FormControl>
        </div>
        <div className="app__stats">
          <InputBox
            onClick={(e)=> setCasesType("cases")}
            active={casesType==="cases"}
            title="Coronavirus Cases"
            cases={prettyPrintStat(countryInfo.todayCases)}
            total={prettyPrintStat(countryInfo.cases)}
          />
          <InputBox
            title="Recovered"
            active={casesType==="recovered"}
            onClick={(e)=> setCasesType("recovered")}
            cases={prettyPrintStat(countryInfo.todayRecovered)}
            total={prettyPrintStat(countryInfo.recovered)}
          />
          <InputBox
            title="Deaths"
            active={casesType==="deaths"}
            onClick={(e)=> setCasesType("deaths")}
            cases={prettyPrintStat(countryInfo.todayDeaths)}
            total={prettyPrintStat(countryInfo.deaths)}
          />
        </div>
        <Map
          countries={mapCountries}
          center={mapCenter}
          casesType={casesType}
          zoom={mapZoom}
        />
      </div>
      <Card className="app__right">
        <CardContent>
          <h3>Live Case by country</h3>
          <Table countries={tableData} />
          <h3 className="WorldWideh3">{country} New {casesType}</h3>
          <div className="LineGraph">
            <FormControl className="app__dropdown">
              <Select
                variant="outlined"
                value={casesType}
                onChange={casesTypeChangeHandler}
              >
                <MenuItem value="cases">Cases</MenuItem>
                <MenuItem value="deaths">Deaths</MenuItem>
                <MenuItem value="recovered">Recovered</MenuItem>
              </Select>
            </FormControl>
            <LineGraph country={country} caseType={casesType} />
          </div>
        </CardContent>
      </Card>
    </div>
  );
}

export default App;
