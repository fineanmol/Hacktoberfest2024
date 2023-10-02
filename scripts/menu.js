const menu = {
  'Home': {
    'text': 'Contribute here',
    'href': 'https://github.com/fineanmol/Hacktoberfest2022/blob/master/contributors/contributorsList.js#L1934'
  },'hacktoberfest1':{
'text':'HacktoberFest Project 1',
  'href':'https://github.com/fineanmol/Annoying-submit-button'
  
},'hacktoberfest2':{
'text':'HacktoberFest Project 2',
  'href':'https://github.com/fineanmol/hacktoberfest'
  
},
  //'Others': {
    'Instagram': {
      'text': 'Instagram Connect',
      'href': 'https://instagram.com/fineanmol'
    },
    'Instagram': {
      'text': 'Connect on <i class="fa fa-instagram" style="font-size:22px"></i>',
      'href': 'https://instagram.com/fineanmol'
    },
    'Facebook': {
      'text': '<i class="fa fa-facebook" style="font-size:20px"></i>acebook',
      'href': 'https://www.facebook.com/fineanmol',
      'id': 'facebook'
    },
    'Linkedin': {
      'text': 'Linked<i class="fa fa-linkedin" style="font-size:20px"></i>',
      'href': 'https://www.linkedin.com/in/fineanmol/',
      'id': 'linkedin'
    },
    'NDC': {
      'text': '<i class="fa fa-twitter" style="font-size:20px"></i>Twitter',
      'href': 'https://twitter.com/fineanmol',
      'id': 'tools'
    },
    'Stars': {
      'text': '<a class="github-button" href="https://github.com/fineanmol/Hacktoberfest2022" data-icon="octicon-star" data-show-count="true" aria-label="Star fineanmol/Hacktoberfest2022 on GitHub">Stars</a>',
      'href': 'https://github.com/fineanmol/Hacktoberfest2022',
      'id': 'tools'
    },
    'Forks': {
      'text': '<a class="github-button" href="https://github.com/fineanmol/Hacktoberfest2022/fork" data-icon="octicon-repo-forked" data-show-count="true" aria-label="Fork fineanmol/Hacktoberfest2022 on GitHub">Fork</a>',
      'href': 'https://github.com/fineanmol/Hacktoberfest2022',
      'id': 'tools'
    }
    

}

function buildMenuHTML (obj = {}) {
  let html = ''
  let path = window.location.pathname.split('/')
  let currentPage = path[path.length - 1] === '' ? '/' : path[path.length - 1]

  Object.entries(obj).forEach(([key, item]) => {
    if (key == 'Others') {
      html += '<li class="dropdown">'
      html += '<a class="nav-link nested-dropdown" href="#" id="Others"> Others </a>'
      html += '<div class="dropdown-content">'
      Object.entries(item).forEach(([key, item]) => {
        let isCurrent = (currentPage === item.href)

        html += '<div class="nav-item' + (isCurrent ? ' active' : '') + '">'
        html += '<a target="_blank" class="nav-link" href="' + item.href + '"' + (item.id ? ' id="' + item.id + '"' : '') + '>' + item.text + '</a>'
        html += '</div>'
      })
      html += '</div>'
    } else {
      if (currentPage.indexOf('.html') == -1) {
        currentPage = currentPage.concat('.html')
      }

      let isCurrent = (currentPage === item.href)

      html += '<li class="nav-item' + (isCurrent ? ' active' : '') + '">'
      html += '<a target="_blank" class="nav-link" href="' + item.href + '"' + (item.id ? ' id="' + item.id + '"' : '') + '>' + item.text + '</a>'
      html += '</li>'
    }
  })
  document.getElementById('menu').innerHTML = html
}

function buildMenu () {
  buildMenuHTML(menu)
}

buildMenu()
