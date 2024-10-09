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
  },
  'Instagram': {
      'text': '<i class="fab fa-instagram" aria-hidden="true"></i>',
      'href': 'https://instagram.com/fineanmol',
      'ariaLabel': 'Instagram'
  },
  'Facebook': {
      'text': '<i class="fab fa-facebook-f" aria-hidden="true"></i>',
      'href': 'https://www.facebook.com/fineanmol',
      'id': 'facebook',
      'ariaLabel': 'Facebook'
  },
  'Linkedin': {
      'text': '<i class="fab fa-linkedin-in" aria-hidden="true"></i>',
      'href': 'https://www.linkedin.com/in/fineanmol/',
      'id': 'linkedin',
      'ariaLabel': 'LinkedIn'
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
  'Know more': {
      'text': 'Hacktober Fest 2024',
      'href': 'https://hacktoberfest.com/',
  }
};

function buildMenuHTML(obj = {}) {
  let html = '';
  let path = window.location.pathname.split('/');
  let currentPage = path[path.length - 1] === '' ? '/' : path[path.length - 1];

  Object.entries(obj).forEach(([key, item]) => {
      if (currentPage.indexOf('.html') == -1) {
          currentPage = currentPage.concat('.html');
      }

      let isCurrent = (currentPage === item.href);

      html += '<li class="nav-item' + (isCurrent ? ' active' : '') + '">';
      html += '<a target="_blank" class="nav-link" href="' + item.href + '"' + 
              (item.id ? ' id="' + item.id + '"' : '') + 
              (item.ariaLabel ? ' aria-label="' + item.ariaLabel + '"' : '') + '>' + 
              item.text + '</a>';
      html += '</li>';
  });

  document.getElementById('menu').innerHTML = html;

  // Re-run GitHub buttons script to properly load star and fork counts
  if (window.GitHubBadge) {
      window.GitHubBadge.init();
  }
}

function buildMenu() {
  buildMenuHTML(menu);
}


document.addEventListener('DOMContentLoaded', buildMenu);

window.addEventListener('resize', () => {
  const navbar = document.querySelector('.navbar-nav');
  const menuItems = navbar.querySelectorAll('.nav-item');
  const availableWidth = navbar.offsetWidth;
  let totalWidth = 0;

  menuItems.forEach(item => {
      totalWidth += item.offsetWidth;
      if (totalWidth > availableWidth) {
          item.classList.add('hidden');
      } else {
          item.classList.remove('hidden');
      }
  });
});

window.dispatchEvent(new Event('resize'));