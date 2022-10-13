import React, { Component } from 'react';
import PropTypes from 'prop-types';
import 'brace';
import 'brace/mode/html';
import 'brace/theme/chrome';
import AceEditor from 'react-ace';

import 'sass/editor';
import data from '../data';

export default class Editor extends Component {
  onEditorChange(html) {
    this.props.onUpdateHtml(html);
  }
  onEditorLoad(editor) {
    editor.session.setUseWorker(false);
    editor.session.setUseWrapMode(true);
  }
  onExampleChange(example) {
    this.props.onUpdateExample(example);
  }

  onViewChange(view) {
    this.props.onSetView(view);
  }

  generateViewLinks(activeView) {

    const views = [
      { id:'html', label:'HTML' },
      { id: 'options', label:'Options' }
    ];

    return views.map(view => {
      const contents = view.id === activeView ?
        view.label : <a href="#" onClick={e => { e.preventDefault(); this.onViewChange(view.id); } }>{view.label}</a>;
      return <li key={ view.id }>{contents}</li>;
    });

  }

  generateEditor(view) {

    const editorProps = {
      $blockScrolling: Infinity,
      wrap: true
    };

    if (view === 'html') {
      const { html } = this.props;
      return <AceEditor mode="html"
                        theme="chrome"
                        name="HTML_EDITOR"
                        value={ html }
                        width="100%"
                        height="auto"
                        onChange={ value => this.onEditorChange(value) }
                        onLoad={ editor => this.onEditorLoad(editor) }
                        editorProps={ editorProps }
      />;
    }
    else {
      const { selectedExample } = this.props;
      const value = data[selectedExample].display ? data[selectedExample].display : `const options = ${JSON.stringify(data[selectedExample].options, null, 2)}`;
      return <AceEditor mode="javascript"
                        theme="chrome"
                        name="HTML_EDITOR"
                        value={ value }
                        width="100%"
                        height="auto"
                        readOnly={ true }
                        onLoad={ editor => this.onEditorLoad(editor) }
                        editorProps={ editorProps }
      />;
    }

  }

  render() {
    const { examples, selectedExample, view } = this.props;
    return (
      <div id="editor">
        <div className="presets">
          <div>
            <select onChange={ e => this.onExampleChange(e.target.value) } value={ selectedExample }>
              { examples.map(example => <option value={ example.value } key={ example.value }>{ example.label}</option>)}
            </select>
          </div>
          <ul>
            { this.generateViewLinks(view) }
          </ul>
        </div>
        { this.generateEditor(view) }
      </div>
    );
  }
}

Editor.propTypes = {
  html: PropTypes.string.isRequired,
  onUpdateHtml: PropTypes.func.isRequired
};
