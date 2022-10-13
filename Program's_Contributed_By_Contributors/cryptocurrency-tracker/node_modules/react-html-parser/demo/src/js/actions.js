export function updateHtml(html) {
  return {
    type: 'UPDATE_HTML',
    html
  };
}

export function updateSelectedExample(example) {
  return {
    type: 'UPDATE_SELECTED_EXAMPLE',
    example
  };
}

export function setView(view) {
  return {
    type: 'SET_VIEW',
    view
  };
}
