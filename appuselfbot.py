import collections
import datetime
import math
import subprocess
import asyncio
import random
import glob
import gc
import psutil
import sys
import re
import traceback
import argparse
import os
import logging
import requests
import logging.handlers
import discord
from bs4 import BeautifulSoup
from json import load, dump
from datetime import timezone
from cogs.utils.dataIO import dataIO
from cogs.utils.allmsgs import custom, quickcmds
from cogs.utils.webhooks import Webhook
from cogs.utils.checks import *
from cogs.utils.config import *
from collections import namedtuple
from discord.ext import commands


FakeGuild = namedtuple("FakeGuild", ["name", "id", "icon_url", "members", "me", "channels", "emojis"])

def parse_cmd_arguments():  # allows for arguments
    parser = argparse.ArgumentParser(description="Discord-Selfbot")
    parser.add_argument("-test", "--test-run",  # test run flag for Travis
                        action="store_true",
                        help="Makes the bot quit before trying to log in")
    parser.add_argument("--force-mac",  # Allows for Testing of mac related code
                        action="store_true",
                        help="Forces to run the Mac checks")
    parser.add_argument("--reset-config",  # Allows for Testing of mac related code
                        action="store_true",
                        help="Reruns the setup")
    parser.add_argument("-s", "--silent",  # Allows for Testing of mac related code
                        action="store_true",
                        help="Supresses all errors")
    return parser


args = parse_cmd_arguments().parse_args()
_test_run = args.test_run
_force_mac = args.force_mac
_reset_cfg = args.reset_config
_silent = args.silent
_force_admin = False

try:
    import uvloop
except ImportError:
    pass
else:
    asyncio.set_event_loop_policy(uvloop.EventLoopPolicy())

try:
    token = os.environ['TOKEN']
    heroku = True
except KeyError:
    heroku = False

if _test_run:
    try:
        samples = os.listdir('settings')  # generating the config files from sample while building
        for f in samples:
            if f.endswith('sample') and f[:-7] not in samples:
                with open('settings/%s' % f, 'r', encoding="utf8") as template:
                    with open('settings/%s' % f[:-7], 'w', encoding="utf8") as g:
                        fields = json.load(template)
                        json.dump(fields, g, sort_keys=True, indent=4)
    except:
        print('Something when wrong. Check for missing sample files')  # only visible in Travis
        pass  # duo to some sample files sometimes missing passing it will make sure nothing goes wrong
    print("Quitting: test run")
    exit(0)

def wizard():
    # setup wizard
    if _silent:
        print('Cannot use setup Wizard becaue of silent mode')
        exit(0)
    config = {}
    print("Welcome to Appu's Discord Selfbot!\nThis setup wizard will guide you through the initial configuration required to get the bot working.\nThe choices you make in this wizard can be changed at any time by editing the settings/config.json file.\n")
    
    print("The first step is to set up your token.")
    print("Go into your Discord window and press Ctrl+Shift+I (Ctrl+Opt+I can also work on macOS)")
    print("Then, go into the Applications tab (you may have to click the arrow at the top right to get there), expand the 'Local Storage' dropdown, select discordapp, and then grab the token value at the bottom. Here's how it looks: https://imgur.com/h3g9uf6")
    print("Paste the contents of that entry below.")
    print("-------------------------------------------------------------")
    config["token"] = input("| ").strip().strip('"')
    
    config["cmd_prefix"] = False
    while not config["cmd_prefix"]:
        print("\nEnter the command prefix you want to use for main commands (e.g. if you enter > you will use commands like so: >about).")
        print("-------------------------------------------------------------")
        config["cmd_prefix"] = input("| ").strip()
        if not config["cmd_prefix"]:
            print("Empty command prefixes are invalid.")
            
    config["customcmd_prefix"] = False
    while not config["customcmd_prefix"]:
        print("\nEnter the command prefix you want to use for custom commands (commands that you add to the bot yourself with custom replies). Using the same prefix as the main command prefix is allowed, but not recommended.")
        print("-------------------------------------------------------------")
        config["customcmd_prefix"] = input("| ").strip()
        if not config["customcmd_prefix"]:
            print("Empty command prefixes are invalid.")
    
    print("\nEnter something that will precede every response from the bot. This is to distinguish bot responses from normal user chatter i.e. Entering :robot: will make the bot respond with the robot emoji at the front of every message it sends.")
    print("-------------------------------------------------------------")
    config["bot_identifier"] = input("| ").strip()

    print("\nWould you like information about your usage of the bot to be recorded for statistic purposes? All information is anonymous and cannot be tracked back to you. (Y/N)")
    print("-------------------------------------------------------------")
    config["track"] = "y" in input("| ").strip().lower()
    
    input("\nThis concludes the setup wizard. For further setup options (ex. setting up google image search), refer to the Discord Selfbot wiki.\n\nYour settings:\nInvoke commands with: {cmd}  Ex: {cmd}ping\nInvoke custom commands with: {custom}  Ex: {custom}get good\nYou may restart this wizard at any time by deleting config.json in the settings folder.\n\nPress Enter to start the bot....\n".format(cmd=config["cmd_prefix"], custom=config["customcmd_prefix"]))
  
    print("Starting up...")
    with open('settings/config.json', encoding='utf-8', mode="w") as f:
        dump(config, f, sort_keys=True, indent=4)


if _reset_cfg and not heroku:
    wizard()
else:
    try:
        with open('settings/config.json', encoding='utf-8', mode="r") as f:
            data = load(f)  # checks if the settings file is valid json file
    except IOError:
        if not heroku:
            wizard()
        else:
            print("Error: Heroku environment detected, but config.json not found!\nThis is usually due to user error during Heroku setup.")
            exit(-1)

shutdown = False
if os.name == 'nt':
    try:
        # only windows users with admin privileges can read the C:\windows\temp
        temp = os.listdir(os.sep.join([os.environ.get('SystemRoot', 'C:\\windows'), 'temp']))
    except:
        shutdown = False
    else:
        shutdown = True
else:
    if os.geteuid() == 0:
        shutdown = True
    else:
        shutdown = False
        
if shutdown is True and not _force_admin:
    if os.name == 'nt':
        print('It is not advised to run the bot as Admin.\nContinuing logging in...')
    else:
        print('It is not advised to run the bot with root privileges.\nContinuing logging in...')


def set_log():
    errformat = logging.Formatter(
        '%(asctime)s %(levelname)s %(module)s %(funcName)s %(lineno)d: '
        '%(message)s',
        datefmt="[%d/%m/%Y %H:%M]")

    logger = logging.getLogger("discord")
    logger.setLevel(logging.INFO)
    stdout_handler = logging.StreamHandler(sys.stdout)
    stdout_handler.setLevel(logging.INFO)

    if not os.path.exists('settings/logs'):
        os.makedirs('settings/logs')
    errhandler = logging.handlers.RotatingFileHandler(
        filename='settings/logs/bot.log', encoding='utf-8', mode='a',
        maxBytes=10**7, backupCount=5)
    errhandler.setFormatter(errformat)

    logger.addHandler(errhandler)

    return logger


logger = set_log()

samples = os.listdir('settings')
for f in samples:
    if f.endswith('sample') and f.rsplit('.', 1)[0] not in samples:
        with open('settings/%s' % f, 'r', encoding="utf8") as template:
            with open('settings/%s' % f.rsplit('.', 1)[0], 'w', encoding="utf8") as g:
                fields = json.load(template)
                json.dump(fields, g, sort_keys=True, indent=4)


bot = commands.Bot(command_prefix=get_config_value('config', 'cmd_prefix'), description='''Selfbot by appu1232''', self_bot=True)

if __name__ == "__main__":
    _runs_in_loop = False
else:
    _runs_in_loop = True

bot.bot_prefix = get_config_value('config', 'bot_identifier')
if bot.bot_prefix != '':
    bot.bot_prefix += ' '

bot.cmd_prefix = get_config_value('config', 'cmd_prefix')
bot.customcmd_prefix = get_config_value('config', 'customcmd_prefix')
bot.track = get_config_value('config', 'track', None)
if bot.track is None:
    print("Would you like information about your usage of the bot to be recorded for statistic purposes? All information is anonymous and cannot be tracked back to you. (Y/N)")
    print("-------------------------------------------------------------")
    bot.track = "y" in input("| ").strip().lower()
    write_config_value("config", "track", bot.track)

# Startup
@bot.event
async def on_ready():
    message = 'logged in as %s' % bot.user
    uid_message = 'user id %s' % bot.user.id
    separator = '-' * max(len(message), len(uid_message))
    print(separator)
    try:
        print(message)
    except: # some bot usernames with special chars fail on shitty platforms
        print(message.encode(errors='replace').decode())
    print(uid_message)
    if bot.track:
        print("anonymous tracking of bot usage is enabled")
    print("'unclosed client session' and 'unclosed connector' are not errors")
    print(separator)

    bot.session = aiohttp.ClientSession(loop=bot.loop, headers={"User-Agent": "AppuSelfBot"})

    bot.uptime = datetime.datetime.now()
    bot.icount = bot.message_count = bot.mention_count = bot.keyword_log = 0
    bot.self_log = bot.all_log = {}
    bot.imagedumps = []
    bot.is_stream = False
    bot.game = bot.game_interval = bot.avatar = bot.avatar_interval = bot.subpro = bot.keyword_found = None
    bot.game_time = bot.avatar_time = bot.gc_time = bot.refresh_time = time.time()
    bot.notify = load_notify_config()
    bot.command_count = {}
    bot.channel_last = [None, None]
    if not os.path.isfile('settings/ignored.json'):
        with open('settings/ignored.json', 'w', encoding="utf8") as fp:
            json.dump({'servers': []}, fp, indent=4)
    with open('settings/ignored.json', encoding="utf8") as fp:
        bot.ignored_servers = json.load(fp)

    if os.path.isfile('restart.txt'):
        with open('restart.txt', 'r', encoding="utf8") as re:
            channel = bot.get_channel(int(re.readline()))
            print('Bot has restarted.')
            await channel.send(bot.bot_prefix + 'Bot has restarted.')
        os.remove('restart.txt')
    bot.log_conf = load_log_config()
    bot.key_users = bot.log_conf['keyusers']

    if os.path.isfile('settings/games.json'):
        with open('settings/games.json', 'r+', encoding="utf8") as g:
            games = json.load(g)
            if type(games['games']) is list:
                bot.game = games['games'][0]
                bot.game_interval = games['interval']
            else:
                bot.game = games['games']
            if 'stream' not in games:
                games['stream'] = 'no'
            if games['stream'] == 'yes':
                bot.is_stream = True
            try:
                bot.status_type = games['status']
            except KeyError:
                bot.status_type = discord.ActivityType.playing
            g.seek(0)
            g.truncate()
            json.dump(games, g, indent=4)

    # Dealing with old versions updating
    if not os.path.isfile('settings/fc.json'):
        data = {"bnet_fc": "", "ds_fc": "", "psn_fc": "", "steam_fc": "", "switch_fc": "", "xbox_fc": ""}
        dataIO.save_json("settings/fc.json", data)
    if not os.path.isfile('settings/replacements.json'):
        data = {":lennyface:": "( ͡° ͜ʖ ͡°)", ":tableflip": "(╯°□°）╯︵ ┻━┻"}
        dataIO.save_json("settings/replacements.json", data)
    if not os.path.isfile('settings/moderation.json'):
        with open('settings/moderation.json', 'w', encoding="utf8") as m:
            mod = {}
            json.dump(mod, m, indent=4)
    if not os.path.isfile('settings/todo.json'):
        with open('settings/todo.json', 'w', encoding="utf8") as t:
            todo = {}
            json.dump(todo, t, indent=4)

    if not os.path.exists('avatars'):
        os.makedirs('avatars')
    if not os.path.isfile('settings/avatars.json'):
        with open('settings/avatars.json', 'w', encoding="utf8") as avis:
            json.dump({'password': '', 'interval': '0', 'type': 'random'}, avis, indent=4)
    with open('settings/avatars.json', 'r', encoding="utf8") as g:
        avatars = json.load(g)
    bot.avatar_interval = avatars['interval']
    if os.listdir('avatars') and avatars['interval'] != '0':
        all_avis = os.listdir('avatars')
        all_avis.sort()
        avi = random.choice(all_avis)
        bot.avatar = avi
    if not os.path.isfile('settings/optional_config.json'):
        conf = load_config()
        o_conf = {'google_api_key': conf['google_api_key'], 'custom_search_engine': conf['custom_search_engine'], 'mal_username': conf['mal_username'], 'mal_password': conf['mal_password']}
        with open('settings/optional_config.json', 'w', encoding="utf8") as oc:
            json.dump(o_conf, oc, indent=4)
    with open('settings/optional_config.json', 'r+', encoding="utf8") as fp:
        opt = json.load(fp)
        if 'embed_color' not in opt:
            opt['embed_color'] = ''
        if 'quoteembed_color' not in opt:
            opt['quoteembed_color'] = 'bc0b0b'
        if 'customcmd_color' not in opt:
            opt['customcmd_color'] = '27007A'
        if 'rich_embed' not in opt:
            opt['rich_embed'] = 'on'
        if 'default_status' not in opt:
            opt['default_status'] = 'idle'
        if 'ascii_font' not in opt:
            opt['ascii_font'] = 'big'
        if 'timezone' not in opt:
            opt['timezone'] = ''
        if '24hours' not in opt:
            opt['24hours'] = 'true'
        if 'password' not in opt:
            opt['password'] = ''
        if avatars['password'] != '' and opt['password'] == '':
            opt['password'] = avatars['password']
        bot.default_status = opt['default_status']
        fp.seek(0)
        fp.truncate()
        json.dump(opt, fp, indent=4)

    if not os.path.isfile('settings/github.json'):
        with open('settings/github.json', 'w', encoding="utf8") as fp:
            git = {}
            json.dump(git, fp, indent=4)
    with open('settings/github.json', 'r+', encoding="utf8") as fp:
        opt = json.load(fp)
        if 'username' not in opt:
            opt['username'] = ''
        if 'password' not in opt:
            opt['password'] = ''
        if 'reponame' not in opt:
            opt['reponame'] = ''
        fp.seek(0)
        fp.truncate()
        json.dump(opt, fp, indent=4)

    notif = load_notify_config()
    if notif['type'] == 'dm':
        if os.path.exists('notifier.txt'):
            pid = open('notifier.txt', 'r', encoding="utf8").read()
            try:
                p = psutil.Process(int(pid))
                p.kill()
            except:
                pass
            os.remove('notifier.txt')
        bot.subpro = subprocess.Popen([sys.executable, 'cogs/utils/notify.py'])
        with open('notifier.txt', 'w', encoding="utf8") as fp:
            fp.write(str(bot.subpro.pid))


@bot.after_invoke
async def after_any_command(ctx):
    if not ctx.command_failed:
        if str(ctx.command) not in bot.command_count:
            bot.command_count[str(ctx.command)] = 1
        else:
            bot.command_count[str(ctx.command)] += 1


@bot.event
async def on_command_error(ctx, error):
    if isinstance(error, commands.errors.CommandNotFound):
        pass
    elif isinstance(error, commands.errors.CheckFailure):
        await ctx.send(bot.bot_prefix + "You don't have permissions to use that command.")
    elif isinstance(error, commands.errors.MissingRequiredArgument):
        formatter = commands.formatter.HelpFormatter()
        help = await formatter.format_help_for(ctx, ctx.command)
        await ctx.send(bot.bot_prefix + "You are missing required arguments.\n" + help[0])
    elif isinstance(error, commands.errors.BadArgument):
        await ctx.send(bot.bot_prefix + "You have given an invalid argument.")
    else:
        if _silent:
            await ctx.send(bot.bot_prefix + "An error occurred with the `{}` command.".format(ctx.command.name))
        else:
            await ctx.send(bot.bot_prefix + "An error occurred with the `{}` command. Check the console for details.".format(ctx.command.name))
            print("Ignoring exception in command {}".format(ctx.command.name))
            trace = traceback.format_exception(type(error), error, error.__traceback__)
            print("".join(trace))


@bot.command(pass_context=True, aliases=['reboot'])
async def restart(ctx):
    """Restarts the bot."""
    def check(msg):
        if msg:
            return (msg.content.lower().strip() == 'y' or msg.content.lower().strip() == 'n') and msg.author == bot.user
        else:
            return False

    latest = update_bot(True)
    if latest:
        await ctx.send(bot.bot_prefix + 'There is an update available for the bot. Download and apply the update on restart? (y/n)')
        reply = await bot.wait_for("message", check=check)
        with open('restart.txt', 'w', encoding="utf8") as re:
            re.write(str(ctx.message.channel.id))
        if not reply or reply.content.lower().strip() == 'n':
            print('Restarting...')
            await ctx.send(bot.bot_prefix + 'Restarting...')
        else:
            try:
                await ctx.send(content=None, embed=latest)
            except:
                pass
            with open('quit.txt', 'w', encoding="utf8") as q:
                q.write('update')
            print('Downloading update and restarting...')
            await ctx.send(bot.bot_prefix + 'Downloading update and restarting (check your console to see the progress)...')

    else:
        print('Restarting...')
        with open('restart.txt', 'w', encoding="utf8") as re:
            re.write(str(ctx.message.channel.id))
        await ctx.send(bot.bot_prefix + 'Restarting...')

    if bot.subpro:
        bot.subpro.kill()
    os._exit(0)


@bot.command(pass_context=True, aliases=['upgrade'])
async def update(ctx, msg: str = None):
    """Update the bot if there is an update available."""
    if msg:
        latest = update_bot(False) if msg == 'show' else update_bot(True)
    else:
        latest = update_bot(True)
    if latest:
        if not msg == 'show':
            if embed_perms(ctx.message):
                try:
                    await ctx.send(content=None, embed=latest)
                except:
                    pass
            await ctx.send(bot.bot_prefix + 'There is an update available. Downloading update and restarting (check your console to see the progress)...')
        else:
            try:
                await ctx.send(content=None, embed=latest)
            except:
                pass
            return
        with open('quit.txt', 'w', encoding="utf8") as q:
            q.write('update')
        with open('restart.txt', 'w', encoding="utf8") as re:
            re.write(str(ctx.message.channel.id))
        if bot.subpro:
            bot.subpro.kill()
        os._exit(0)
    else:
        await ctx.send(bot.bot_prefix + 'The bot is up to date.')


@bot.command(pass_context=True, aliases=['stop', 'shutdown'])
async def quit(ctx):
    """Quits the bot."""
    print('Bot exiting...')
    if bot.subpro:
        bot.subpro.kill()
    open('quit.txt', 'a', encoding="utf8").close()
    await ctx.send(bot.bot_prefix + 'Bot shut down.')
    os._exit(0)


@bot.command(pass_context=True)
async def reload(ctx, txt: str = None):
    """Reloads all modules."""
    await ctx.message.delete()
    if txt:
        bot.unload_extension(txt)
        try:
            bot.load_extension(txt)
        except Exception as e:
            try:
                bot.load_extension(txt)
            except:
                await ctx.send('``` {}: {} ```'.format(type(e).__name__, e))
                return
    else:
        utils = []
        for i in bot.extensions:
            utils.append(i)
        l = len(utils)
        utils.append(utils.pop(utils.index('cogs.help')))
        for i in utils:
            bot.unload_extension(i)
            try:
                bot.load_extension(i)
            except Exception as e:
                await ctx.send('{}Failed to reload module `{}` ``` {}: {} ```'.format(bot.bot_prefix, i, type(e).__name__, e))
                l -= 1
        await ctx.send(bot.bot_prefix + 'Reloaded {} of {} modules.'.format(l, len(utils)))

# On all messages sent (for quick commands, custom commands, and logging messages)
@bot.event
async def on_message(message):

    if hasattr(bot, 'message_count'):
        bot.message_count += 1

    # If the message was sent by me
    if message.author.id == bot.user.id:
        if ">>" in message.content:
            if message.content.rsplit(">>", 1)[0] != "":
                if message.content.rsplit(">>", 1)[1].strip().isdigit():
                    if bot.get_channel(int(message.content.rsplit(">>", 1)[1].strip())):
                        message.content, new_channel = message.content.rsplit(">>", 1)
                        if new_channel.strip().isdigit():
                            message.channel = bot.get_channel(int(new_channel.strip()))
                        elif new_channel.strip() == "" and bot.channel_last[0] != None:
                            message.channel = bot.get_channel(bot.channel_last[0])

        if hasattr(bot, 'channel_last'):
            if message.channel and message.channel.id not in bot.channel_last:
                bot.channel_last.pop(0)
                bot.channel_last.append(message.channel.id)
        if hasattr(bot, 'icount'):
            bot.icount += 1
        try:
            if hasattr(bot, 'ignored_servers'):
                if any(str(message.guild.id) == str(guild_id) for guild_id in bot.ignored_servers['servers']):
                    return
        except AttributeError:  # Happens when it's a direct message.
            pass
        if hasattr(bot, 'self_log'):
            try:
                if str(message.channel.id) not in bot.self_log:
                    bot.self_log[str(message.channel.id)] = collections.deque(maxlen=100)
            except AttributeError:
                return
            bot.self_log[str(message.channel.id)].append(message)
            if message.content.startswith(bot.customcmd_prefix):
                response = custom(message.content.lower().strip())
                if response:
                    await message.delete()
                    if get_config_value('optional_config', 'rich_embed') == 'on':
                        if response[0] == 'embed' and embed_perms(message):
                            try:
                                if get_config_value('optional_config', 'customcmd_color'):
                                    color = int('0x' + get_config_value('optional_config', 'customcmd_color'), 16)
                                    await message.channel.send(content=None, embed=discord.Embed(colour=color).set_image(url=response[1]))
                                else:
                                    await message.channel.send(content=None, embed=discord.Embed().set_image(url=response[1]))
                            except:
                                await message.channel.send(response[1])
                        else:
                            await message.channel.send(response[1])
                    else:
                        await message.channel.send(response[1])
            else:
                response = quickcmds(message.content.lower().strip())
                if response:
                    await message.delete()
                    await message.channel.send(response)

    notified = message.mentions
    if notified:
        for i in notified:
            if i.id == bot.user.id:
                bot.mention_count += 1

    if not hasattr(bot, 'log_conf'):
        bot.log_conf = load_log_config()
        
    if isinstance(message.channel, discord.abc.PrivateChannel):
        add_alllog(str(message.channel.id), "DM", message)
    else:
        add_alllog(str(message.channel.id), str(message.guild.id), message)

    # Keyword logging.
    if bot.log_conf['keyword_logging'] == 'on' and isinstance(message.channel, discord.abc.GuildChannel):

        try:
            word_found = False
            if (bot.log_conf['allservers'] == 'True' or str(message.guild.id) in bot.log_conf['servers']) and (str(message.guild.id) not in bot.log_conf['blacklisted_servers'] and str(message.channel.id) not in bot.log_conf['blacklisted_channels']):
                if message.author.id != bot.user.id and (not message.author.bot and not any(x in str(message.author.id) for x in bot.log_conf['blacklisted_users'])) and message.author not in bot.user.blocked:
                    for word in bot.log_conf['keywords']:
                        if ' [server]' in word:
                            word, guild = word.split(' [server]')
                            if str(message.guild.id) != guild:
                                continue
                        elif ' [channel]' in word:
                            word, channel = word.split(' [channel]')
                            if str(message.channel.id) != channel:
                                continue
                        if word.startswith('[isolated]'):
                            word = word[10:].lower()
                            found = re.findall(r'\b' + re.escape(word) + r'\b', message.content.lower())
                            if found:
                                word_found = True
                                break
                        else:
                            if word.lower() in message.content.lower():
                                word_found = True
                                break

                    for x in bot.log_conf['blacklisted_words']:
                        if '[server]' in x:
                            bword, id = x.split('[server]')
                            if bword.strip().lower() in message.content.lower() and str(message.guild.id) == id:
                                word_found = False
                                break
                        elif '[channel]' in x:
                            bword, id = x.split('[channel]')
                            if bword.strip().lower() in message.content.lower() and str(message.channel.id) == id:
                                word_found = False
                                break
                        if x.lower() in message.content.lower():
                            word_found = False
                            break

            user_found = False
            if bot.log_conf['user_logging'] == 'on':
                if '{} {}'.format(str(message.author.id), str(message.guild.id)) in bot.log_conf['keyusers']:
                    user = '{} {}'.format(str(message.author.id), str(message.guild.id))
                    cd_active, user_p = user_post(bot.key_users, user)
                    if cd_active:
                        bot.log_conf['keyusers'][user] = bot.key_users[user] = user_p
                        user_found = message.author.name

                elif '{} all'.format(str(message.author.id)) in bot.log_conf['keyusers']:
                    user = '{} all'.format(str(message.author.id), str(message.guild.id))
                    cd_active, user_p = user_post(bot.key_users, user)
                    if cd_active:
                        bot.log_conf['keyusers'][user] = bot.key_users[user] = user_p
                        user_found = message.author.name

            if word_found is True or user_found:
                if bot.log_conf['user_location'] != bot.log_conf['log_location'] and bot.log_conf['user_location'] != '' and not word_found:
                    location = bot.log_conf['user_location'].split()
                    is_separate = True
                else:
                    location = bot.log_conf['log_location'].split()
                    is_separate = False
                guild = bot.get_guild(int(location[1]))
                if str(message.channel.id) != location[0]:
                    msg = message.clean_content.replace('`', '')

                    context = []
                    total_context = 0
                    try:
                        for i in range(1, min(int(bot.log_conf['context_len']), len(bot.all_log[str(message.channel.id) + ' ' + str(message.guild.id)]))):
                            context.append(bot.all_log[str(message.channel.id) + ' ' + str(message.guild.id)][len(bot.all_log[str(message.channel.id) + ' ' + str(message.guild.id)])-i-1])
                            total_context += 1
                    except IndexError:  # This usually means that the bot's internal log has not been sufficiently populated yet
                        pass
                    msg = ''
                    for i in range(0, total_context):
                        temp = context[len(context)-i-1][0]
                        if temp.clean_content:
                            msg += 'User: %s | %s\n' % (temp.author.name, temp.created_at.replace(tzinfo=timezone.utc).astimezone(tz=None).__format__('%x @ %X')) + temp.clean_content.replace('`', '') + '\n\n'
                    msg += 'User: %s | %s\n' % (message.author.name, message.created_at.replace(tzinfo=timezone.utc).astimezone(tz=None).__format__('%x @ %X')) + message.clean_content.replace('`', '')
                    part = int(math.ceil(len(msg) / 1950))
                    if user_found:
                        title = '%s posted' % user_found
                    else:
                        title = '%s mentioned: %s' % (message.author.name, word)
                    if part == 1:
                        em = discord.Embed(timestamp=message.created_at, color=0xbc0b0b, title=title, description='Server: ``%s``\nChannel: <#%s> | %s\n\n**Context:**' % (str(message.guild), str(message.channel.id), message.channel.name))
                        while context:
                            temp = context.pop()
                            if temp[0].clean_content:
                                em.add_field(name='%s' % temp[0].author.name, value=temp[0].clean_content, inline=False)
                        em.add_field(name='%s' % message.author.name, value=message.clean_content, inline=False)
                        try:
                            em.set_thumbnail(url=message.author.avatar_url)
                        except:
                            pass
                        if bot.notify['type'] == 'msg':
                            await webhook(em, 'embed', is_separate)
                        elif bot.notify['type'] == 'ping':
                            await webhook(em, 'embed ping', is_separate)
                        else:
                            await guild.get_channel(int(location[0])).send(embed=em)
                    else:
                        split_list = [msg[i:i + 1950] for i in range(0, len(msg), 1950)]
                        all_words = []
                        split_msg = ''
                        for i, blocks in enumerate(split_list):
                            for b in blocks.split('\n'):
                                split_msg += b + '\n'
                            all_words.append(split_msg)
                            split_msg = ''
                        if user_found:
                            logged_msg = '``%s`` posted' % user_found
                        else:
                            logged_msg = '``%s`` mentioned' % word
                        for b, i in enumerate(all_words):
                            if b == 0:
                                if bot.notify['type'] == 'msg':
                                    await webhook(bot.bot_prefix + '%s in server: ``%s`` Context: Channel: <#%s> | %s\n\n```%s```' % (logged_msg, str(message.guild), str(message.channel.id), message.channel.name, i), 'message', is_separate)
                                elif bot.notify['type'] == 'ping':
                                    await webhook(bot.bot_prefix + '%s in server: ``%s`` Context: Channel: <#%s> | %s\n\n```%s```' % (logged_msg, str(message.guild), str(message.channel.id), message.channel.name, i), 'message ping', is_separate)
                                else:
                                    await guild.get_channel(int(location[0])).send(bot.bot_prefix + '%s in server: ``%s`` Context: Channel: <#%s>\n\n```%s```' % (logged_msg, str(message.guild), str(message.channel.id), i))
                            else:
                                if bot.notify['type'] == 'msg':
                                    await webhook('```%s```' % i, 'message', is_separate)
                                elif bot.notify['type'] == 'ping':
                                    await webhook('```%s```' % i, 'message ping', is_separate)
                                else:
                                    await guild.get_channel(int(location[0])).send('```%s```' % i)
                    bot.keyword_log += 1

        # Bad habit but this is for skipping errors when dealing with Direct messages, blocked users, etc. Better to just ignore.
        except (AttributeError, discord.errors.HTTPException):
            pass

    
    await bot.process_commands(message)


def add_alllog(channel, guild, message):
    if not hasattr(bot, 'all_log'):
        bot.all_log = {}
    if channel + ' ' + guild in bot.all_log:
        bot.all_log[channel + ' ' + guild].append((message, message.clean_content))
    else:
        bot.all_log[channel + ' ' + guild] = collections.deque(maxlen=int(get_config_value('log', 'log_size', 25)))
        bot.all_log[channel + ' ' + guild].append((message, message.clean_content))


def remove_alllog(channel, guild):
    del bot.all_log[channel + ' ' + guild]


# Webhook for keyword notifications
async def webhook(keyword_content, send_type, is_separate):
    if not is_separate:
        temp = bot.log_conf['webhook_url'].split('/')
    else:
        temp = bot.log_conf['webhook_url2'].split('/')
    channel = temp[len(temp) - 2]
    token = temp[len(temp) - 1]
    webhook_class = Webhook(bot)
    request_webhook = webhook_class.request_webhook
    if send_type.startswith('embed'):
        if 'ping' in send_type:
            await request_webhook('/{}/{}'.format(channel, token), embeds=[keyword_content.to_dict()], content=bot.user.mention)
        else:
            await request_webhook('/{}/{}'.format(channel, token), embeds=[keyword_content.to_dict()], content=None)
    else:
        if 'ping' in send_type:
            await request_webhook('/{}/{}'.format(channel, token), content=keyword_content + '\n' + bot.user.mention, embeds=None)
        else:
            await request_webhook('/{}/{}'.format(channel, token), content=keyword_content, embeds=None)

# Set/cycle game
async def game_and_avatar(bot):
    await bot.wait_until_ready()
    current_game = next_game = current_avatar = next_avatar = 0

    while True:
        # Cycles game if game cycling is enabled.
        try:
            if hasattr(bot, 'game_time') and hasattr(bot, 'game'):
                if bot.game:
                    if bot.game_interval:
                        game_check = game_time_check(bot.game_time, bot.game_interval)
                        if game_check:
                            bot.game_time = game_check
                            with open('settings/games.json', encoding="utf8") as g:
                                games = json.load(g)
                            if games['type'] == 'random':
                                while next_game == current_game:
                                    next_game = random.randint(0, len(games['games']) - 1)
                                current_game = next_game
                                bot.game = games['games'][next_game]
                                if bot.is_stream and '=' in games['games'][next_game]:
                                    g, url = games['games'][next_game].split('=')
                                    await bot.change_presence(activity=discord.Streaming(name=g,
                                                                                url=url),
                                                              status=set_status(bot), afk=True)
                                else:
                                    await bot.change_presence(activity=discord.Activity(name=games['games'][next_game], type=bot.status_type), status=set_status(bot), afk=True)
                            else:
                                if next_game+1 == len(games['games']):
                                    next_game = 0
                                else:
                                    next_game += 1
                                bot.game = games['games'][next_game]
                                if bot.is_stream and '=' in games['games'][next_game]:
                                    g, url = games['games'][next_game].split('=')
                                    await bot.change_presence(activity=discord.Streaming(name=g, url=url), status=set_status(bot), afk=True)
                                else:
                                    await bot.change_presence(activity=discord.Activity(name=games['games'][next_game], type=bot.status_type), status=set_status(bot), afk=True)

                    else:
                        game_check = game_time_check(bot.game_time, 180)
                        if game_check:
                            bot.game_time = game_check
                            with open('settings/games.json', encoding="utf8") as g:
                                games = json.load(g)

                            bot.game = games['games']
                            if bot.is_stream and '=' in games['games']:
                                g, url = games['games'].split('=')
                                await bot.change_presence(activity=discord.Streaming(name=g, url=url), status=set_status(bot), afk=True)
                            else:
                                await bot.change_presence(activity=discord.Activity(name=games['games'], type=bot.status_type), status=set_status(bot), afk=True)

            # Cycles avatar if avatar cycling is enabled.
            if hasattr(bot, 'avatar_time') and hasattr(bot, 'avatar'):
                if bot.avatar:
                    if bot.avatar_interval:
                        avi_check = avatar_time_check(bot.avatar_time, bot.avatar_interval)
                        if avi_check:
                            bot.avatar_time = avi_check
                            with open('settings/avatars.json', encoding="utf8") as g:
                                avi_config = json.load(g)
                            all_avis = os.listdir('avatars')
                            all_avis.sort()
                            if avi_config['type'] == 'random':
                                while next_avatar == current_avatar:
                                    next_avatar = random.randint(0, len(all_avis) - 1)
                                current_avatar = next_avatar
                                bot.avatar = all_avis[next_avatar]
                                with open('avatars/%s' % bot.avatar, 'rb') as fp:
                                    await bot.user.edit(password=avi_config['password'], avatar=fp.read())
                            else:
                                if next_avatar + 1 == len(all_avis):
                                    next_avatar = 0
                                else:
                                    next_avatar += 1
                                bot.avatar = all_avis[next_avatar]
                                with open('avatars/%s' % bot.avatar, 'rb') as fp:
                                    await bot.user.edit(password=avi_config['password'], avatar=fp.read())

            # Sets status to default status when user goes offline (client status takes priority when user is online)
            if hasattr(bot, 'refresh_time'):
                refresh_time = has_passed(bot.refresh_time)
                if refresh_time:
                    bot.refresh_time = refresh_time
                    if bot.game and bot.is_stream and '=' in bot.game:
                        g, url = bot.game.split('=')
                        await bot.change_presence(activity=discord.Streaming(name=g, url=url), status=set_status(bot), afk=True)
                    elif bot.game and not bot.is_stream:
                        await bot.change_presence(activity=discord.Activity(name=bot.game, type=bot.status_type),
                                                  status=set_status(bot), afk=True)
                    else:
                        await bot.change_presence(status=set_status(bot), afk=True)

            if hasattr(bot, 'gc_time'):
                gc_t = gc_clear(bot.gc_time)
                if gc_t:
                    gc.collect()
                    bot.gc_time = gc_t

        except Exception as e:
            print('Something went wrong: %s' % e)

        await asyncio.sleep(5)

if __name__ == '__main__':
    err = sys.stderr
    sys.stderr = open(os.devnull, 'w')
    if not os.path.exists("custom_cogs"):
        try:
            os.makedirs("custom_cogs")
            text = "Hello! Seems like you ran into this folder and don't know what this is for. This folder is meant to hold various custom cogs you can download.\n\n" \
                   "Custom cogs are additional add-ons you can download for the bot which will usually come with additional features and commands.\n\n" \
                   "For more info on what they are, how they can be accessed and downloaded, and how you can make one too, go here: https://github.com/appu1232/Discord-Selfbot/wiki/Other-Add-ons"
            with open("custom_cogs/what_is_this.txt", 'w') as fp:
                fp.write(text)
            site = requests.get('https://github.com/LyricLy/ASCII/tree/master/cogs').text
            soup = BeautifulSoup(site, "html.parser")
            data = soup.find_all(attrs={"class": "js-navigation-open"})
            list = []
            for a in data:
                list.append(a.get("title"))
            for cog in list[2:]:
                for entry in list[2:]:
                    response = requests.get("http://appucogs.tk/cogs/{}".format(entry))
                    found_cog = response.json()
                    filename = found_cog["link"].rsplit("/", 1)[1].rsplit(".", 1)[0]
                    if os.path.isfile("cogs/" + filename + ".py"):
                        os.rename("cogs/" + filename + ".py", "custom_cogs/" + filename + ".py")
        except Exception as e:
            print("Failed to transfer custom cogs to custom_cogs folder. Error: %s" % str(e))
    for extension in os.listdir("cogs"):
        if extension.endswith('.py'):
            try:
                bot.load_extension("cogs." + extension[:-3])
            except Exception as e:
                print('Failed to load extension {}\n{}: {}'.format(extension, type(e).__name__, e))
    for extension in os.listdir("custom_cogs"):
        if extension.endswith('.py'):
            try:
                bot.load_extension("custom_cogs." + extension[:-3])
            except Exception as e:
                print('Failed to load extension {}\n{}: {}'.format(extension, type(e).__name__, e))

    sys.stderr = err
    bot.loop.create_task(game_and_avatar(bot))

    while True:
        if heroku:
            token = os.environ['TOKEN']
        else:
            token = get_config_value('config', 'token')
        try:
            bot.run(token, bot=False)
        except discord.errors.LoginFailure:
            if not heroku:
                if _silent:
                    print('Cannot use setup Wizard becaue of silent mode')
                    exit(0)
                print("It seems the token you entered is incorrect or has changed. If you changed your password or enabled/disabled 2fa, your token will change. Grab your new token. Here's how you do it:\n")
                print("Go into your Discord window and press Ctrl+Shift+I (Ctrl+Opt+I can also work on macOS)")
                print("Then, go into the Applications tab (you may have to click the arrow at the top right to get there), expand the 'Local Storage' dropdown, select discordapp, and then grab the token value at the bottom. Here's how it looks: https://imgur.com/h3g9uf6")
                print("Paste the contents of that entry below.")
                print("-------------------------------------------------------------")
                token = input("| ").strip('"')
                with open("settings/config.json", "r+", encoding="utf8") as fp:
                    config = json.load(fp)
                    config["token"] = token
                    fp.seek(0)
                    fp.truncate()
                    json.dump(config, fp, indent=4)
                continue
        break
