const menu = {
  'Home': {
    'text': 'Home',
    'href': 'https://github.com/fineanmol/Hacktoberfest2k18'
  },
  'Contributors': {
    'text': 'Contributors',
    'href': 'index.html'
  },
  'Others': {
    'Potato': {
      'text': 'A to Z Resources for Students',
      'href': 'https://github.com/dipakkr/A-to-Z-Resources-for-Students'
    },
    'Tools': {
      'text': 'Tools',
      'href': 'tools.html',
      'id': 'tools'
    },
    'Invert': {
      'text': 'Invert',
      'href': '#',
      'id': 'invert-btn'
    },
    'Fireworks': {
      'text': 'Fireworks',
      'href': 'Fireworks.html',
      'id': 'fireworks'
    },
    'Learn': {
      'text': 'Learn!',
      'href': 'wow.html',
      'id': 'learn'
    },
    'Bubble': {
      'text': 'Bubble',
      'href': 'bubble.html',
      'id': 'Bubble'
    },
    'Canoi': {
      'text': 'Canoi',
      'href': 'canoi.html',
      'id': 'Canoi'
    },
    'Colorgame': {
      'text': 'Colorgame',
      'href': 'colorgame.html',
      'id': 'Colorgame'
    },
    'Foxy': {
      'text': 'Foxy',
      'href': 'foxy.html',
      'id': 'Foxy'
    },
    'Gifheaven': {
      'text': 'Gif Heaven',
      'href': 'gifheaven.html',
      'id': 'Gifheaven'
    },
    'Plainpage': {
      'text': 'Plain Page',
      'href': 'plain_page.html',
      'id': 'Plainpage'
    },
    'Snek': {
      'text': 'Snek',
      'href': 'snek.html',
      'id': 'Snek'
    },
    
    'Values': {
      'text': 'Values',
      'href': 'values.html',
      'id': 'Values'
    },
     'Flappy': {
      'text': 'Flappy Game',
      'href': 'Flappy.html',
      'id': 'Flappy'
    },
    'Stay Dry': {
      'text': 'Stay Dry',
      'href': '/dry',
      'id': 'dry'
    }
  }
}

function buildMenuHTML (obj = {}) {
  var html = ''
  var path = window.location.pathname.split('/')
  var currentPage = path[path.length - 1] === '' ? '/' : path[path.length - 1]

  Object.entries(obj).forEach(([key, item]) => {
    if (key == 'Others') {
      html += '<li class="dropdown">'
      html += '<a class="nav-link nested-dropdown" href="#" id="Others"> Others </a>'
      html += '<div class="dropdown-content">'
      Object.entries(item).forEach(([key, item]) => {
        let isCurrent = (currentPage === item.href)

        html += '<div class="nav-item' + (isCurrent ? ' active' : '') + '">'
        html += '<a class="nav-link" href="' + item.href + '"' + (item.id ? ' id="' + item.id + '"' : '') + '>' + item.text + '</a>'
        html += '</div>'
      })
      html += '</div>'
    } else {
      if (currentPage.indexOf('.html') == -1) {
        currentPage = currentPage.concat('.html');
      }

      let isCurrent = (currentPage === item.href)

      html += '<li class="nav-item' + (isCurrent ? ' active' : '') + '">'
      html += '<a class="nav-link" href="' + item.href + '"' + (item.id ? ' id="' + item.id + '"' : '') + '>' + item.text + '</a>'
      html += '</li>'
    }
  })
  document.getElementById('menu').innerHTML = html
}

function buildMenu () {
  return buildMenuHTML(menu)
}

buildMenu()
