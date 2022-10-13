import React from 'react';
import PropTypes from 'prop-types';
import ReactHtmlParser from 'react-html-parser';

import 'sass/html';

import data from '../data';

export default function Html(props) {
  const { html, selectedExample } = props;
  const options = data[selectedExample].options;
  return (
    <div id="html">
      { ReactHtmlParser(html, options) }
    </div>
  );
}

Html.propTypes = {
  html: PropTypes.string.isRequired
};
