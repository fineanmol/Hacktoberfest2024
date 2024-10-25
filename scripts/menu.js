const menu = {
  'Home': {
    'text': 'Contribute here',
    'href': 'https://github.com/fineanmol/Hacktoberfest2022/blob/master/contributors/contributorsList.js#L1934'
  },
  'hacktoberfest1': {
    'text': 'HacktoberFest Project 1',
    'href': 'https://github.com/fineanmol/Annoying-submit-button'
  },
  'hacktoberfest2': {
    'text': 'HacktoberFest Project 2',
    'href': 'https://github.com/fineanmol/hacktoberfest'
  }
}

const socialmenu = {
  'Emptyone': {
    'text': '<span style="display: flex; align-items: center;"><i style="font-size:25px; "></i><<<<</span>',
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
  },
  'Emptytwo': {
    'text': '<span style="display: flex; align-items: center;"><i style="font-size:25px; "></i>>>>></span>',
  },
  'Instagram': {
    'text': '<span style="display: flex; align-items: center;"><i class="fa fa-instagram" style="font-size:22px; margin-left: 7px; margin-right: 5px;"></i>Instagram</span>',
    'href': 'https://instagram.com/fineanmol'
  },
  'Facebook': {
    'text': '<span style="display: flex; align-items: center;"><i class="fa fa-facebook" style="font-size:20px;"></i>acebook</span>',
    'href': 'https://www.facebook.com/fineanmol',
    'id': 'facebook'
  },
  'Linkedin': {
    'text': '<span style="display: flex; align-items: center;">Linked<i class="fa fa-linkedin" style="font-size:20px; margin-right: 5px;"></i></span>',
    'href': 'https://www.linkedin.com/in/fineanmol/',
    'id': 'linkedin'
  },
  'NDC': {
    'text': '<span style="display: flex; align-items: center;"><i class="fa fa-twitter" style="font-size:20px; margin-right: 5px;"></i>Twitter</span>',
    'href': 'https://twitter.com/fineanmol',
    'id': 'tools'
  }
}

function buildMenuHTML(obj = {}, targetId) {
  let html = ''
  let path = window.location.pathname.split('/')
  let currentPage = path[path.length - 1] === '' ? '/' : path[path.length - 1]

  Object.entries(obj).forEach(([key, item]) => {
    if (currentPage.indexOf('.html') == -1) {
      currentPage = currentPage.concat('.html')
    }

    let isCurrent = (currentPage === item.href)

    html += '<li class="nav-item' + (isCurrent ? ' active' : '') + '">'
    html += '<a target="_blank" class="nav-link"' + (item.href ? ' href="' + item.href + '"' : '') + (item.id ? ' id="' + item.id + '"' : '') + '>' + item.text + '</a>'
    html += '</li>'
  })

  document.getElementById(targetId).innerHTML = html
}

function buildMenu() {
  buildMenuHTML(menu, 'menu')         // Populate main menu
  buildMenuHTML(socialmenu, 'socialmenu') // Populate social menu
}

buildMenu()