import os
import os.path
import base64
import zipfile
import re
import compileall
import argparse
import io

PY_SHIM = '''
import sys
import os
import os.path
import runpy
import maya.cmds
import traceback
try:
    melfile = __keystone_file
    lastmod = os.path.getmtime(melfile)
    zipfolder = maya.cmds.about(pd=True) + "/keystones"
    zipname = zipfolder + "/" + os.path.basename(melfile) + ".zip"
    print "// starting keystone launcher"
    should_update = not os.path.exists(zipname)
    if not should_update:
        should_update = os.path.getmtime(zipname) < lastmod
    if should_update:
        if not os.path.exists(zipfolder):
            os.makedirs(zipfolder)
            print "// created keystone directory"
        with open(melfile, 'rb') as binary_blob:
            print "// extracting environment from ", melfile
            binary_blob.seek(__keystone_offset)
            with open(zipname, "wb") as output:
                print "//  copy to ", zipname
                contents = binary_blob.read(40960)
                while contents:
                    output.write(contents)
                    contents = binary_blob.read(40960)
    sys.path.insert(0, zipname)
    print "// path inserted"
    # restore missing sys.argv on OSX
    if not melfile in sys.argv:
        args = sys.argv[:]
        args.insert(1, melfile)
        sys.argv = args
        print "// sys.argv: ", sys.argv
    if __keystone_main:
        print "// launch startup"
        runpy.run_path(zipname)
except Exception:
    print traceback.format_exc()
    maya.cmds.error("Keystone boostrap failed")
'''

MEL_SHIM = '''// keystone
global proc keystone_fileid()
{
    string $tokens[];
    tokenize(`whatIs keystone_fileid`, " ", $tokens);
    python("__keystone_file = r'" + $tokens[4] + "'");
};
keystone_fileid();
python("__keystone_offset = %s; __keystone_main = %i; __keystone_version = 2");
python("import base64; __keystone_cmd = base64.urlsafe_b64decode('%s'); exec __keystone_cmd");
'''


def zip_directory(source, zipfilename, ignore=None, include=None):

    compileall.compile_dir(source, maxlevels=24)

    archive = zipfile.ZipFile(zipfilename, 'w')

    py_re = re.compile(".py$")

    if ignore:
        ignore = re.compile(ignore)

    if include:
        include = re.compile(include)

    def iter_files():
        for root, dirs, files in os.walk(source):
            for f in files:
                fullpath = os.path.join(root, f).replace("\\", "/")
                if any(py_re.findall(fullpath)):
                    continue
                if include is not None and any(include.findall(fullpath)):
                    yield fullpath
                    continue
                if ignore is None or not ignore.findall(fullpath):
                    yield fullpath

    offset = len(source)
    try:
        for each_file in iter_files():
            archive.write(each_file, each_file[offset:])
    finally:
        archive.close()

    return zipfilename


def generate_mel(melname, folder, ):
    try:
        zipped = zip_directory(folder, 'keystone_temp.zip')
        encoded = base64.urlsafe_b64encode(PY_SHIM)
        has_main = os.path.exists(folder + "/__main__.py")
        mel_text = MEL_SHIM % ("%s", has_main, encoded)
        offset = len(mel_text) + 3  # get pass the
        offset += len(str(offset))
        mel_text = mel_text % str(offset)
        # this slightly unusual write method ensures that
        # the offset values are identical on all platforms
        with io.open(melname, 'w', newline='\r\n') as output:
            output.write(unicode(mel_text))
            output.write(u'//')

        with open(zipped, 'rb') as zipper:
            with open(melname, 'ab') as mel:
                mel.write(zipper.read())
    finally:
        os.remove(zipped)


def python_to_mel(melfile, pythonfile):
    """
    compile a single python file to an executable mel file
    """
    with open(pythonfile, 'rt') as reader:
        py_code = reader.read()
    encoded = base64.urlsafe_b64encode(py_code)
    py_to_mel = "import base64; _py_code = base64.urlsafe_b64decode('%s'); exec _py_code" % encoded
    with open(melfile, 'wt') as writer:
        writer.write('python("%s");' % py_to_mel)


desc = '''
Compiles a python project into an executable mel file.  If the project folder
contains a __main__.py at the root level, it will be executed when the mel is launched. Any
python modules in the project folder will be added to maya's python path.
'''

if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=desc)
    parser.add_argument('melfile', help="path to the output mel file")
    parser.add_argument('project', help="path to the project folder or script")
    parser.add_argument('--script', help='if true, compile a single python file instead of a folder', action='store_true')
    args = parser.parse_args()

    melfile = os.path.abspath(os.path.normpath(args.melfile))
    if not melfile.endswith(".mel"):
        melfile += ".mel"
    project = os.path.abspath(os.path.normpath(args.project))

    if args.script:
        if not os.path.exists(project):
            raise ValueError("'%s' is not a valid file" % project)

        python_to_mel(melfile, project)

    else:
        if not os.path.isdir(project):
            raise ValueError("'%s' is not a directory" % project)

        generate_mel(melfile, project)
