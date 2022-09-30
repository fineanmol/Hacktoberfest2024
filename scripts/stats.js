let statsObj = {
    commits: 0,
    forks: 0,
    pr: 0,
    stars: 0,
    issues:0,
    contribut:0
}

const reqObj = [
    ['https://api.github.com/repos/fineanmol/Hacktoberfest2021/commits', 'commits'],
    ['https://api.github.com/repos/fineanmol/Hacktoberfest2021/forks', 'forks'],
    ['https://api.github.com/repos/fineanmol/Hacktoberfest2021/pulls', 'pr'],
    ['https://api.github.com/repos/fineanmol/Hacktoberfest2021/issues', 'issues'],
    ['https://api.github.com/repos/fineanmol/Hacktoberfest2021/stargazers', 'stars'],
    ['https://api.github.com/repos/fineanmol/Hacktoberfest2021/stats/contributors', 'contribut'],
]

const getData = (url, key) => {
    fetch(url)
        .then(r => {
        	if(r.ok) {
            if (r.headers.get('Link')) {
                r.headers.get('Link').split(',').forEach(link => {
                    if (link.includes('next')) {
                        link = link.split('<')
                        link = link[1].split('>')
                        getData(link[0], key)
                    }
                })
            }
            return r.json()
           }
           else {
           	throw new Error('Api limit exceeded');
           }
        })
        .then(json => {
            statsObj[key] += json.length
           // document.getElementById('stats').innerHTML = 'Commits: ' + statsObj.commits + ' Forks: ' + statsObj.forks + ' Pull Requests: ' + statsObj.pr + ' Issues: ' + statsObj.issues + ' Stars: ' + statsObj.stars + ' Contributors: ' + statsObj.contribut
	    document.getElementById('stats').innerHTML = 'You guys are awesome, we have passed the github rate again this hour. <a href="https://github.com/fineanmol/Hacktoberfest2021">Here</a> is a link to repo to check out live stats'
        }).catch(() => {
        	console.log('This catched 403');
						document.getElementById('stats').innerHTML = 'You guys are awesome, we have passed the github rate again this hour. <a href="https://github.com/fineanmol/Hacktoberfest2021">Here</a> is a link to repo to check out live stats'
				})
}

reqObj.forEach(rq => {
    getData(rq[0], rq[1])
})
setInterval(() => {
    reqObj.forEach(rq => {
        getData(rq[0], rq[1])
    })
 }, 60000)
