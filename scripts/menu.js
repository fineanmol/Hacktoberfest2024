const menu = {
  'Home': {
    'text': 'Want to Publish?',
    'href': 'https://github.com/fineanmol/Hacktoberfest2k20/blob/master/Contributors.html'
  },
  'Contributors': {
    'text': 'Contributors',
    'href': 'https://fineanmol.github.io/Hacktoberfest2k20/Contributors.html'
  },
  //'Others': {
    'Instagram': {
      'text': 'Instagram Connect',
      'href': 'https://instagram.com/nightowldevelopers'
    },
    'Facebook': {
      'text': 'Facebook',
      'href': 'https://www.facebook.com/nightowldevelopers',
      'id': 'tools'
    },
    'Linkedin': {
      'text': 'Linkedin',
      'href': 'https://www.linkedin.com/company/nightowldevelopers',
      'id': 'tools'
    },
    'NDC': {
      'text': 'About Us',
      'href': 'https://www.nightowldevelopers.com',
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
