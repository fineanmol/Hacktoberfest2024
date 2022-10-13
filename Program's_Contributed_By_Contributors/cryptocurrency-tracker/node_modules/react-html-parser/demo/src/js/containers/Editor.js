import { connect } from 'react-redux';
import { updateHtml, updateSelectedExample, setView } from '../actions';
import Editor from '../components/Editor';

const mapStateToProps = state => {
  return {
    html: state.html,
    examples: state.examples,
    selectedExample: state.selectedExample,
    view: state.view
  };
};

const mapDispatchToProps = dispatch => {
  return {
    onUpdateHtml: html => dispatch(updateHtml(html)),
    onUpdateExample: example => dispatch(updateSelectedExample(example)),
    onSetView: view => dispatch(setView(view))
  };
};

export default connect(
  mapStateToProps,
  mapDispatchToProps
)(Editor);
