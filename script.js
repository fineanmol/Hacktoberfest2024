document.addEventListener('DOMContentLoaded', function () {
    const container = document.querySelector('.animated-container');
    const githubButton = document.querySelector('.animated-github-button');
    const inputs = document.querySelector('.animated-inputs');
    
    // Add the 'loaded' class to trigger animations
    container.classList.add('loaded');
    githubButton.classList.add('loaded');
    inputs.classList.add('loaded');
});
