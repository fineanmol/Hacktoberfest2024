import React from 'react';
import 'sass/app';

import Header from './Header';
import Editor from '../containers/Editor';
import Html from '../containers/Html';

export default function App() {
  return (
    <div id="app">
      <Header />
      <main id="content">
        <Editor />
        <Html />
      </main>
    </div>
  );
}
