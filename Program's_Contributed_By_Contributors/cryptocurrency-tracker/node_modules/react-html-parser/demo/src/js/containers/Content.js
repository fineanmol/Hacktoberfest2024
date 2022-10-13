import { connect } from 'react-redux';
import { updateHtml } from '../actions';
import Content from '../components/Content';

const mapStateToProps = state => {
  return {
    html: state.html
  };
};

const mapDispatchToProps = dispatch => {
  return {
    onUpdateHtml: html => {
      dispatch(updateHtml(html));
    }
  };
};

export default connect(
  mapStateToProps,
  mapDispatchToProps
)(Content);
