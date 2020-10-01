const menu = {
  'Home': {
    'text': 'Want to Publish?',
    'href': 'https://github.com/fineanmol/Hacktoberfest2k18/blob/master/Contributors.html'
  },
  'Contributors': {
    'text': 'Contributors',
    'href': 'https://fineanmol.github.io/Hacktoberfest2k18/Contributors.html'
  },
  //'Others': {
    'Deepak': {
      'text': 'A to Z Resources for Students',
      'href': 'https://github.com/dipakkr/A-to-Z-Resources-for-Students'
    },
    'Tools': {
      'text': 'Age Converter',
      'href': 'https://fineanmol.github.io/AgeGame',
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
