const menu = {
  'Home': {
    'text': 'Contribute here',
    'href': 'https://github.com/fineanmol/Hacktoberfest2022/blob/master/contributors/contributorsList.js#L1934'
  },
  'Hacktoberfest1': {
    'text': 'HacktoberFest Project 1',
    'href': 'https://github.com/fineanmol/Annoying-submit-button'
  },
  'Hacktoberfest2': {
    'text': 'HacktoberFest Project 2',
    'href': 'https://github.com/fineanmol/hacktoberfest'
  },
  'Social': {
    'Instagram': {
      'text': 'Connect on <i class="fa fa-instagram" style="font-size:22px;"></i>',
      'href': 'https://instagram.com/fineanmol'
    },
    'Facebook': {
      'text': '<i class="fa fa-facebook" style="font-size:20px;"></i> Facebook',
      'href': 'https://www.facebook.com/fineanmol',
      'id': 'facebook'
    },
    'Linkedin': {
      'text': 'Linked<i class="fa fa-linkedin" style="font-size:20px;"></i>',
      'href': 'https://www.linkedin.com/in/fineanmol/',
      'id': 'linkedin'
    },
    'Twitter': {
      'text': '<i class="fa fa-twitter" style="font-size:20px;"></i> Twitter',
      'href': 'https://twitter.com/fineanmol',
      'id': 'tools'
    }
  },
  'Github': {
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
};

function buildMenuHTML(obj = {}) {
  let html = '';

  // Handle both trailing and non-trailing slash in current path (consistently remove trailing slash)
  const path = window.location.pathname.replace(/\/$/, ''); // Remove trailing slash
  const currentPage = path.split('/').pop();

  Object.entries(obj).forEach(([key, item]) => {
    if (key === 'Social' || key === 'Github') { // Handle grouped menu items
      html += '<li class="dropdown">';
      html += `<a class="nav-link nested-dropdown" href="#" id="${key}">${key}</a>`;
      html += '<div class="dropdown-content">';

      Object.entries(item).forEach(([subKey, subItem]) => {
        let isCurrent = currentPage === subItem.href;
        html += '<div class="nav-item' + (isCurrent ? ' active' : '') + '">';
        html += '<a target="_blank" class="nav-link" href="' + subItem.href + '"' + (subItem.id ? ' id="' + subItem.id + '"' : '') + '>' + subItem.text + '</a>';
        html += '</div>';
      });

      html += '</div>'; // Close dropdown-content
      html += '</li>'; // Close dropdown
    } else {
      let isCurrent = currentPage === item.href;
      html += '<li class="nav-item' + (isCurrent ? ' active' : '') + '">';
      html += '<a target="_blank" class="nav-link" href="' + item.href + '"' + (item.id ? ' id="' + item.id + '"' : '') + '>' + item.text + '</a>';
      html += '</li>';
    }
  });

  document.getElementById('menu').innerHTML = html;
}

function buildMenu() {
  buildMenuHTML(menu);
}

buildMenu();
