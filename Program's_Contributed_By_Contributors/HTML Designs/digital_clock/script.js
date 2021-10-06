
setInterval(digitalClock,500)
		function digitalClock() {
			let dt = new Date();
			let hr = dt.getHours();
			let min = dt.getMinutes();
			let sec = dt.getSeconds();
			let tz = " AM "
			
			if (hr  < 10) {
				hr ='0' + hr;
			}
			if (min  < 10) {
				min="0" + min;
			}
			if (sec  < 10) {
				sec ="0" + sec;
			}
			if (hr>=12) {
				hr = hr -12
				tz = " PM"
			}

			if (hr == 0 ) {
				hr = 12

			}

			document.getElementById("clock").innerHTML = hr + " : " + min + " : " + sec + tz;
		}

