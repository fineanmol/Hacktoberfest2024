import { connect } from 'react-redux';
import Content from '../components/Html';

const mapStateToProps = state => {
  return {
    html: state.html,
    selectedExample: state.selectedExample
  };
};

export default connect(
  mapStateToProps
)(Content);
