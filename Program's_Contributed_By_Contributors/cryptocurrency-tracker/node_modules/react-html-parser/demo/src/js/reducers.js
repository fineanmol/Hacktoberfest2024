import data from './data';

const initialExample = 'simple';

const initialState = {
  html: data[initialExample].html,
  examples: [
    { value: 'simple', label: 'Simple Example' },
    { value: 'entities', label: 'Don\'t Decode HTML Entities' },
    { value: 'transform', label: 'Transform' }
  ],
  selectedExample: initialExample,
  view: 'html'
};

export default function reducer(state=initialState, action) {

  switch (action.type) {
    case 'UPDATE_HTML':
      return {
        ...state,
        html: action.html
      };
    case 'UPDATE_SELECTED_EXAMPLE':
      return {
        ...state,
        html: data[action.example].html,
        selectedExample: action.example
      };
    case 'SET_VIEW':
      return {
        ...state,
        view: action.view
      };
    default:
      return state;
  }

}
