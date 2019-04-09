Support FAQ - thanks to Skelt0r


# Introduction
Welcome to the support FAQ. You'll find the answers to the most frequently asked questions. You might have been forwarded here in case you asked a question in #live-support. All questions and answers are numbered for easy forwarding. Please let me know by DM if something is missing. Please help others in #live-support by forwarding them here (when appropriate).

# Q0: I haven't received my masternode reward. When can I expect it?
## A0: You should check the current reward interval on the explorer website (http://explorer2.darkpaycoin.io/). The first reward takes around 3x the normal reward interval. 


# Q1: My wallet is stuck at block number xxx.xxx, what should I do?
## A1: You should resync your wallet as follows:
1. Stop your wallet,
2. Go to your wallet folder,
In Win:  %APPDATA%\DarkPayCoin
In OSX: ~/Library/Application Support/DarkPayCoin
In Linux: ~/.DarkPayCoin
3. Remove chainstate and blocks folders and the file peers.dat
4. Download dpc_fastsync.zip from https://darkpaycoin.io/utils/dpc_fastsync.zip
5. Unzip dpc_fastsync.zip in wallet folder.
6. Start wallet and let it sync.


# Q2: I'm not sure whether I am on the right chain, how can I check?
## A2: You should check a blockhash of your wallet/masternode with the explorer as follows:

Control wallet:
1. Open debug console (Tools-> Debug console),
2. Type getblockcount,
3. Use the number from #2 in the following command: getblockhash xxx.xxx
4. Go to explorer (http://explorer2.darkpaycoin.io/) and paste the result from #3 (or the block number)

If there is no result or it shows you a different block number, you are on the wrong chain. A fix is described in Q1. If you entered the block number in explorer, the result should be the same as the result of #3.

Masternode
1. Log in via ssh
2. darkpaycoin-cli getblockcount
3. Use the number from #2 in the following command: darkpaycoin-cli getblockhash xxx.xxx
4. Go to explorer (http://explorer2.darkpaycoin.io/) and paste the result from #3 (or the block number)

If there is no result or it shows you a different block number, you are on the wrong chain. A fix is described in Q3. If you entered the block number in explorer, the result should be the same as the result of #3.


# Q3: My masternode is on the wrong chain, how can I fix this?
## A3: You should resync your masternode chain as follows:

1. Log in via ssh
2. cd /root/.darkpaycoin
3. service darkpaycoin stop
4. rm -R blocks && rm -R chainstate && rm peers.dat
5. wget https://darkpaycoin.io/utils/dpc_fastsync.zip
6. unzip dpc_fastsync.zip
7. service darkpaycoin start

You can check the output of debug.log as follows:
tail -f /root/.darkpaycoin/debug.log

The above command can be killed by pushing ctrl and c keys simultaneously.

You can check the status of your masternode as follows:
darkpaycoin-cli masternode status

The last 2 lines of the result should be:
"status": 4,
"message": "Masternode successfully started"

If it's not, check Q4.


# Q5: I'd like to reinstall my Windows wallet, what should I do?
## A5: You should remove the wallet files and registry entry as follows:

1. First make a backup of your wallet.dat, darkpaycoin.conf and masternode.conf files located in %APPDATA%\DarkPayCoin (additionally you can also make copy of backups folder, so you also have access to older backups of your wallet.dat)
2. Push Windows key+r
3. Type regedit
4. Rename or delete following key: computer\H_KEY_CURRENT_USER\Software\DarkPayCoin
5. Install wallet as normal
6. Copy the backed-up files from #1 to the darkpaycoin folder (%APPDATA%\DarkPayCoin)
7. Start wallet and let it sync. (for quickest sync, see fix in Q1)


# Q6: How can I install a MN on Tor?
## A6: Use the multi install script as follows:

1. Log in your vps
2. If you're not logged in as root: sudo su
3. cd /root
4. wget https://raw.githubusercontent.com/Skelt0r/darkpay/master/dpc_mn_tor_multi_install.sh
5. chmod +x dpc_mn_tor_multi_install.sh
6. ./dpc_mn_tor_multi_install.sh -t
7. Follow the installer and use the .onion address you get in the end instead of the IP in the MN line in masternode.conf

In order to be able to activate the Tor MN you need to install a Tor proxy as follows:

Ubuntu
8. Follow instructions here: https://www.torproject.org/docs/debian.html.en
9. Activate proxy in wallet settings, use 127.0.0.1 and port 9050 (these are already prefilled) You can also add a line in your wallet config file (darkpaycoin.conf): proxy=127.0.0.1:9050

Windows
8. Download the Expert Bundle from here: https://www.torproject.org/download/download.html.en
9. Unzip under C:/ so you'll have C:\Tor\tor.exe
10. Press Win+x and select "Windows PowerShell (Administrator)"
11. In the window that opens, type: C:\Tor\tor.exe --service install
12. Activate proxy in wallet settings, use 127.0.0.1 and port 9050 (these are already prefilled) You can also add a line in your wallet config file (darkpaycoin.conf): proxy=127.0.0.1:9050


OSX
8. Follow instructions here: https://www.torproject.org/docs/tor-doc-osx.html.en
9. Activate proxy in wallet settings, use 127.0.0.1 and port 9050 (these are already prefilled) You can also add a line in your wallet config file (darkpaycoin.conf): proxy=127.0.0.1:9050

You wallet will sync slower than normal, because all wallet traffic is routed through Tor. Wait for ~20 confirmations of the collateral transaction before activating the masternode + check the MN status in your vps: darkpaycoin-cli --datadir=/root/.darkpaycoin1 masternode status (remove the 1 if this is the first masternode on this vps, replace by a 2 if this is the third etc)


# Q7: How can I run a DarkPay wallet on OSX without using the OSX wallet?
## A7: You could run a Virtual Machine (VM) with an Ubuntu Desktop and run the Ubuntu wallet on it as follows:

1. Download VirtualBox, go to https://www.virtualbox.org/wiki/Downloads
2. Click OSX hosts and install the .dmg 
3. Download and install Vagrant: https://releases.hashicorp.com/vagrant/2.2.2/vagrant_2.2.2_x86_64.dmg 
4. Open a terminal and run following commands:
5. mkdir ubuntu-18.04-desktop-amd64 $$ cd ubuntu-18.04-desktop-amd64
6. vagrant init peru/ubuntu-18.04-desktop-amd64
7. vagrant up
 
Wait a while and you have an Ubuntu Desktop in a virtual machine. Don't forget to change the default password as follows:
8. Open a terminal in Ubuntu
9. Run the following command: passwd (and follow instructions)
10. Download the wallet as normal


# Q8: how do I install multiple masternodes on the same VPS using IPv6?
## A8: check out this guide made by @h6y34ui98 :



# Q9: ADDNODES?

46.101.231.40

142.93.97.228

167.99.220.116

206.189.173.84

165.227.172.190

159.65.144.67

128.199.198.131

178.62.80.178

128.199.203.152

138.68.108.10

