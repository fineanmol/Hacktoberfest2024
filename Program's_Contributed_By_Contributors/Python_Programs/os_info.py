import platform as os;

version_info = os.version()
release = os.release()
platform = os.platform()
system = os.system()


os_info = '''Platform: {platform}
Version: {version_info}
Release: {release}
System: {system}'''.format(platform=platform, version_info=version_info, release=release, system=system)
print(os_info);
