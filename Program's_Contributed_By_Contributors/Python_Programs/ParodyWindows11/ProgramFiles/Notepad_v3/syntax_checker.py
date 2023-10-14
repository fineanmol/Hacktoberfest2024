""" syntax checker"""
import keyword
import tkinter.messagebox
import inspect
from importlib import resources
import io


class SyntaxChecker(object):
    """ syntax checker for programming languages"""

    def __init__(self, text: tkinter.Text, root: tkinter.Tk):
        self.text = text
        self.root = root

    def syntax_python(self, e=None):
        """ syntax checker"""
        self.text.bind("<Key>", self.syntax_python)
        import pkgutil
        import builtins
        builtin_function_names = dir(builtins)
        _words = keyword.kwlist
        index = self.text.search("\\s", "insert", backwards=True, regexp=True)
        if index == "":
            index = 1.0
        else:
            index = self.text.index(f"{index}+1c")
        word = self.text.get(index, "insert")
        possible_module_names = [module[1] for module in
                                 list(pkgutil.iter_modules())]

        if word in _words:
            self.text.tag_remove("VariableNames", index, f"{index}"
                                                         f"+{len(word)}c")
            self.text.tag_remove("FunctionNames", index, f"{index}"
                                                         f"+{len(word)}c")
            self.text.tag_remove("ModuleNames", index, f"{index}+{len(word)}c")
            self.text.tag_remove("CorrectSyntax", index, f"{index}"
                                                         f"+{len(word)}c")
            self.text.tag_add("CorrectSyntax", index, f"{index}+{len(word)}c")
            self.text.tag_configure("CorrectSyntax", foreground="orange")
        elif word in possible_module_names:
            self.text.tag_remove("VariableNames", index, f"{index}"
                                                         f"+{len(word)}c")
            self.text.tag_remove("FunctionNames", index, f"{index}"
                                                         f"+{len(word)}c")
            self.text.tag_remove("CorrectSyntax", index, f"{index}"
                                                         f"+{len(word)}c")
            self.text.tag_remove("ModuleNames", index, f"{index}+{len(word)}c")
            self.text.tag_add("ModuleNames", index, f"{index}+{len(word)}c")
            self.text.tag_configure("ModuleNames", foreground="violet")
        elif word in builtin_function_names:
            self.text.tag_remove("VariableNames", index, f"{index}"
                                                         f"+{len(word)}c")
            self.text.tag_remove("CorrectSyntax", index, f"{index}+"
                                                         f"{len(word)}c")
            self.text.tag_remove("ModuleNames", index, f"{index}+{len(word)}c")
            self.text.tag_remove("FunctionNames", index, f"{index}+"
                                                         f"{len(word)}c")
            self.text.tag_add("FunctionNames", index, f"{index}+{len(word)}c")
            self.text.tag_configure("FunctionNames", foreground="blue")
        else:
            self.text.tag_add("VariableNames", index, f"{index}+{len(word)}c")
            self.text.tag_configure("VariableNames", foreground="green")
        self.text.focus_set()

    def syntax_JS(self, event=None):
        """ syntax for JavaScript devs"""

        def addBackTicks(e=None):
            """ add back ticks for JS"""
            import tkinter
            print("called addBackTicks() function")
            indexer = self.text.index(tkinter.INSERT)
            self.text.insert(indexer, "`")
            self.text.mark_set(tkinter.INSERT, "insert-1c")

        self.text.bind("<Key>", self.syntax_JS)
        self.root.bind("`", addBackTicks)
        functions = ['constructor', 'toExponential', 'toFixed',
                     'toLocaleString', 'toPrecision', 'toString', 'valueOf',
                     'toSource', 'charAt', 'charCodeAt', 'concat', 'indexOf',
                     'lastIndexOf', 'localeCompare', 'length', 'match',
                     'replace', 'search', 'slice', 'split', 'substr',
                     'substring', 'toLocaleLowerCase', 'toLocaleUpperCase',
                     'toLowerCase', 'toUpperCase', 'anchor', 'big', 'blink',
                     'bold', 'fixed', 'fontcolor', 'fontsize', 'italics',
                     'link', 'small', 'sub', 'sup', 'every', 'filter',
                     'forEach', 'join', 'map', 'pop', 'push', 'reduce',
                     'reduceRight', 'reverse', 'shift', 'some', 'sort',
                     'splice', 'unshift', 'Date', 'getDate', 'getDay',
                     'getFullYear', 'getHours', 'getMilliseconds',
                     'getMinutes', 'getMonth', 'getSeconds', 'getTime',
                     'getTimezoneOffset', 'getUTCDate', 'getUTCDay',
                     'getUTCFullYear', 'getUTCHours', 'getUTCMilliseconds',
                     'getUTCMinutes', 'getUTCMonth', 'getUTCSeconds',
                     'getYear', 'setDate', 'setYear', 'setFullYear',
                     'setHours', 'setMonth', 'setSeconds', 'setTime',
                     'setMinutes', 'setMilliseconds', 'setUTCDate',
                     'setUTCHours', 'setUTCFullYear', 'setUTCMinutes',
                     'setUTCMonth', 'setUTCSeconds', 'setUTCMilliseconds',
                     'toLocaleDateString', 'toLocateTimeString',
                     'toTimeString', 'toUTCString', 'abs', 'acos', 'asin',
                     'atan', 'atan2', 'ceil', 'cos', 'exp', 'floor', 'log',
                     'max', 'min', 'pow', 'random', 'round', 'sin', 'sqrt',
                     'tan', 'exec', 'test', 'console', 'Array', 'String',
                     'Number', 'prompt']
        _words = ['function', 'let', 'const', 'var', 'switch', ';', 'new',
                  'break', 'continue']
        index = self.text.search("\\s", "insert", backwards=True, regexp=True)
        if index == "":
            index = 1.0
        else:
            index = self.text.index(f"{index}+1c")
        word = self.text.get(index, "insert")

        if word in _words:
            self.text.tag_remove("VariableNames", index, f"{index}"
                                                         f"+{len(word)}c")
            self.text.tag_remove("FunctionNames", index, f"{index}"
                                                         f"+{len(word)}c")
            self.text.tag_remove("ModuleNames", index, f"{index}+{len(word)}c")
            self.text.tag_remove("CorrectSyntax", index, f"{index}"
                                                         f"+{len(word)}c")
            self.text.tag_add("CorrectSyntax", index, f"{index}+{len(word)}c")
            self.text.tag_configure("CorrectSyntax", foreground="orange")
        # elif word in possible_module_names:
        #     self.text.tag_remove("VariableNames", index, f"{index}"
        #                                                  f"+{len(word)}c")
        #     self.text.tag_remove("FunctionNames", index, f"{index}"
        #                                                  f"+{len(word)}c")
        #     self.text.tag_remove("CorrectSyntax", index, f"{index}"
        #                                                  f"+{len(word)}c")
        #    self.text.tag_remove("ModuleNames", index, f"{index}+{len(word)}c")
        #     self.text.tag_add("ModuleNames", index, f"{index}+{len(word)}c")
        #     self.text.tag_configure("ModuleNames", foreground="violet")
        elif word in functions:
            self.text.tag_remove("VariableNames", index, f"{index}"
                                                         f"+{len(word)}c")
            self.text.tag_remove("CorrectSyntax", index, f"{index}+"
                                                         f"{len(word)}c")
            self.text.tag_remove("ModuleNames", index, f"{index}+{len(word)}c")
            self.text.tag_remove("FunctionNames", index, f"{index}+"
                                                         f"{len(word)}c")
            self.text.tag_add("FunctionNames", index, f"{index}+{len(word)}c")
            self.text.tag_configure("FunctionNames", foreground="blue")
        else:
            self.text.tag_add("VariableNames", index, f"{index}+{len(word)}c")
            self.text.tag_configure("VariableNames", foreground="green")
        self.text.focus_set()

    def syntax_C(self, event=None):
        """ syntax C """
        self.root.bind("<Key>", self.syntax_C)
        module_functions = ["assert.h", "complex.h", "float.h", "limits.h",
                            "math.h", "stdio.h", "time.h", "time.h", "string.h"]
        statements = ["#include", "#define", "restrict", "int", "double",
                      "return", "void", 'break', 'auto', 'const', 'float',
                      'short', 'struct', 'unsigned', 'continue', 'else',
                      'for', 'long', 'signed', 'switch', 'case', 'default',
                      'enum', 'goto', 'register', 'sizeof', 'typedef',
                      'volatile', 'char', 'do', 'extern', 'if', 'static',
                      'union', 'while']
        index = self.text.search("\\s", "insert", backwards=True, regexp=True)
        if index == "":
            index = 1.0
        else:
            index = self.text.index(f"{index}+1c")
        word = self.text.get(index, "insert")

        if word in statements:
            self.text.tag_remove("VariableNames", index, f"{index}"
                                                         f"+{len(word)}c")
            # self.text.tag_remove("FunctionNames", index, f"{index}"
            #                                              f"+{len(word)}c")
            self.text.tag_remove("ModuleNames", index, f"{index}+{len(word)}c")
            self.text.tag_remove("CorrectSyntax", index, f"{index}"
                                                         f"+{len(word)}c")
            self.text.tag_add("CorrectSyntax", index, f"{index}+{len(word)}c")
            self.text.tag_configure("CorrectSyntax", foreground="orange")
        elif word in module_functions:
            self.text.tag_remove("VariableNames", index, f"{index}"
                                                         f"+{len(word)}c")
            self.text.tag_remove("CorrectSyntax", index, f"{index}+"
                                                         f"{len(word)}c")
            self.text.tag_remove("ModuleNames", index, f"{index}+{len(word)}c")
            # add remove tag for functions names (only builtins) if added!
            self.text.tag_add("ModuleNames", index, f"{index}+{len(word)}c")
            self.text.tag_configure("ModuleNames", foreground="violet")
        else:
            self.text.tag_add("VariableNames", index, f"{index}+{len(word)}c")
            self.text.tag_configure("VariableNames", foreground="green")
        self.text.focus_set()


class SpellCheck(object):
    """ spell check"""

    def __init__(self, text: tkinter.Text, root: tkinter.Tk):
        self.text = text
        self.root = root
        # file_dir = inspect.getfile(lambda: None).rstrip("syntax_checker.py")
        with open("ProgramFiles/Notepad_v3/spellcheck.txt") as reader:
            self.spellcheck_list = reader.read().split("\n")
        self.root.bind("<Key>", self.SpellChecker)

    def SpellChecker(self, event=None):
        """ spell check"""
        index = self.text.search("\\s", "insert", backwards=True, regexp=True)
        if index == "":
            index = 1.0
        else:
            index = self.text.index(f"{index}+1c")
        keys = ('a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l',
                'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x',
                'y', 'z')
        try:
            if event.char in keys:
                word = self.text.get(index, "insert")
                if word not in self.spellcheck_list:
                    self.text.tag_add("Misspelled", index, f"{index}+"
                                                           f"{len(word)}c")
                    self.text.tag_configure("Misspelled", background="red")
                else:
                    self.text.tag_remove("Misspelled", index, f"{index}+"
                                                              f"{len(word)}c")
        except AttributeError:
            pass

    def addToSpellCheck(self, text_to_add: str, event=None):
        """ adding words to spellcheck. """
        if text_to_add not in self.spellcheck_list:
            with open('spellcheck.txt', 'w') as writer:
                writer.write("\n")
                writer.write(text_to_add)
                index = self.text.search(text_to_add, "insert", backwards=True,
                                         regexp=True)
                word = self.text.get(index, f"{index}+{len(text_to_add)}c")
                self.text.tag_remove("Misspelled", index,
                                     f"{index}+{len(word)}c")
            self.spellcheck_list.append(text_to_add)
        else:
            tkinter.messagebox.showwarning("Word Exists", "The selected text "
                                                          "is already in the "
                                                          "word dictionary")
