// Copyright (c) 2010 Satoshi Nakamoto
// Copyright (c) 2009-2014 The Bitcoin developers
// Copyright (c) 2014-2015 The Dash developers
// Copyright (c) 2015-2018 The PIVX developers
// Copyright (c) 2016-2018 The Phore developers
// Copyright (c) 2018-2019 The DarkPayCoin developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "libzerocoin/Params.h"
#include "chainparams.h"
#include "random.h"
#include "util.h"
#include "utilstrencodings.h"

#include <assert.h>

#include <boost/assign/list_of.hpp>

using namespace std;
using namespace boost::assign;

struct SeedSpec6 {
    uint8_t addr[16];
    uint16_t port;
};

#include "chainparamsseeds.h"

/**
 * Main network
 */

//! Convert the pnSeeds6 array into usable address objects.
static void convertSeed6(std::vector<CAddress>& vSeedsOut, const SeedSpec6* data, unsigned int count)
{
    // It'll only connect to one or two seed nodes because once it connects,
    // it'll get a pile of addresses with newer timestamps.
    // Seed nodes are given a random 'last seen time' of between one and two
    // weeks ago.
    const int64_t nOneWeek = 7 * 24 * 60 * 60;
    for (unsigned int i = 0; i < count; i++) {
        struct in6_addr ip;
        memcpy(&ip, data[i].addr, sizeof(ip));
        CAddress addr(CService(ip, data[i].port));
        addr.nTime = GetTime() - GetRand(nOneWeek) - nOneWeek;
        vSeedsOut.push_back(addr);
    }
}

//   What makes a good checkpoint block?
// + Is surrounded by blocks with reasonable timestamps
//   (no blocks before with a timestamp after, none after with
//    timestamp before)
// + Contains no strange transactions
static Checkpoints::MapCheckpoints mapCheckpoints =
    boost::assign::map_list_of
   (0, uint256("0x00000d5bd64fbdfb201c8ebbf2c714a5321c3db9765ff69c482db9e4a609aa18"))
   (1, uint256("0x000009c85fe5c841abdb8eeab9d802b392649282febe7f0d3cbd219ef08361c0"))// genesis is skynet
   (71, uint256("0x000000dc61293f85f14ca9cff59c5d5c0a805c95f1118f1d8891b7498c964343"))// enforce
   (301, uint256("0xdb9141059616919c7b37c228cbca78f696432c73493c0ddfad269297cfd27817"))
   (666, uint256("0x3cb316d52b5cae8354989e28c7261794527a6cbaec0b08abe89b6294f6076107")) // oh Dark Lord make us rich & healthy
   (866, uint256("0xcc4cf4b21367e3debf70de9091d7997767bf07ce92895bce755584308f83fb6f"))
   (2493, uint256("0xf779c5506420c371b6cc63b57e0508bf89a93c7e2ae7482df0082ad30bbedf0e"))
   (4706, uint256("0x3326c110adeca2dd13fc8a91d424f750a340d084104432e5bb3b0d674b4ba0f0")) 
   (7566, uint256("0x631cc3d650388304fa63c8a78fb952584564e80b05801d430145487503c1747b"))
   (10600, uint256("0xbe08af760f08b115c022ad9c22408a78fa9464d43bf157d4367bfadea921d9fd"))
   (13016, uint256("0xd515e008daf60fd4bba97cb650019ef0cc738d49e7a97cba8fa553fbfb06646f"))
   (26136, uint256("0xa79cf58ca088547e71136639768f1df88026ca6d8588a4ed6a7af27f30ff57cc"))
   (26816, uint256("0xa1a089d259b295f2e526e0998d114bf3c8cab150006ba41ea94b30bc44bbe4c8"))
   (58508, uint256("0x4ce3f6793e404332a3f370961892762a98ea3dd60620296ac855172f7e76640b")) 
   (138400, uint256("0xa8ee45b2c404afc36726581d812ec4e9127ba65bc4d8d413f555b9c64b4f322c"))
   (150000, uint256("0xf8914a2c8de7c540a1fe16fecd5f86b7d941d8acd5539f86aa49ad71b7d1baaf")) //may phase2 be with us
   (150006, uint256("0x5e013ace753d4bd3c819f17d88289d3a8f1d966679dc13a29df8f5d5179d4622"))
   (150214, uint256("0x0d700f857e24e7bf2f6d48a2daee615c2b040f5699c0bf33ce73d5c4a97bd8a0"))
   (160308, uint256("0x21e6fc7e3dc08733350a8e4ae8bb178b5f25839de26cd3bf1629a63026817a5e"))
   (161500, uint256("0x8ba50f91af67b4efea4f65440261b9ada30bdd18dda150f362995f4437002fd2"))
   (306000, uint256("0x5606181c43d1622bed0f8d69488e8e6576c476f411a0b8d0a1bf9760f40c83a8"))
   (306001, uint256("0x6c8b2a990e700d9472096ed39792021c347e4d7553e9e8ee1ab22480d8d2aa09"))
   (306044, uint256("0x341337c5ff507e0336dce2b98d45ece2c56a366e51c78ea99fa9e486ff9821a2"))
   (306400, uint256("0xbbd236c0c6ef6487f3fbb444fd44e2dc7c5d116718bd462e0e81eaecbb39ebd4"))
   (306666, uint256("0x569be7bd52d32d3e030550574022b7bb64719d3a4c492029be7605ea917f2629"))
   (306667, uint256("0xd00aa15293728250dad78cc644e1f8c30a88120bbe3098535494747549609510"))
   (306668, uint256("0xc94fc3b92e82a932ab7f6650c17a8d0da3c2ed5a2af0afb077c0af883388026a"))
   (306669, uint256("0xd40c82a43068b80bbdad4ba422e07ef89920bfe1863745b44cc92b3c68a6559c"))
   (306670, uint256("0x9cbebd31ef510557b4340e8eb1e7985bc1aae63010f349f748992b027b68ad10")) // sync whole network
   (306671, uint256("0x2e6c1a3790e0c389f6e4111e58c8a7b526c77ce6a6d41dc5be9203d696fbeac3"))
   (306692, uint256("0xb009eda4facf6025f800e6d53d977c2b4ce6de0de131a185f7bd163108f44f8b")) // UpdateTip: new best=b009eda4facf6025f800e6d53d977c2b4ce6de0de131a185f7bd163108f44f8b  height=306692  log2_work=64.791577  tx=753572  date=2019-04-08 21:05:22 progress=1.000003  cache=2134
   (306705, uint256("0x0c96d8149bb788fbc0750e2fbf2f463236577f35a863697e3f3589b272c0bd0c")); //  new best=0c96d8149bb788fbc0750e2fbf2f463236577f35a863697e3f3589b272c0bd0c  height=306705  log2_work=64.791581  tx=753598  date=2019-04-08 21:19:01 progress=1.000006  cache=2174




static const Checkpoints::CCheckpointData data = {
    &mapCheckpoints,
 	
	1554758341,
    753598,
 //   (the tx=... number in the SetBestChain debug.log lines)


	2666 
};
static Checkpoints::MapCheckpoints mapCheckpointsTestnet =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataTestnet = {
    &mapCheckpointsTestnet,
    1536012006,
    0,
    250};

static Checkpoints::MapCheckpoints mapCheckpointsRegtest =
    boost::assign::map_list_of(0, uint256("0x001"));
static const Checkpoints::CCheckpointData dataRegtest = {
    &mapCheckpointsRegtest,
    1536012007,
    0,
100};

libzerocoin::ZerocoinParams* CChainParams::Zerocoin_Params(bool useModulusV1) const
{
    assert(this);
    static CBigNum bnHexModulus = 0;
    if (!bnHexModulus)
        bnHexModulus.SetHex(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsHex = libzerocoin::ZerocoinParams(bnHexModulus);
    static CBigNum bnDecModulus = 0;
    if (!bnDecModulus)
        bnDecModulus.SetDec(zerocoinModulus);
    static libzerocoin::ZerocoinParams ZCParamsDec = libzerocoin::ZerocoinParams(bnDecModulus);

    if (useModulusV1)
        return &ZCParamsHex;

    return &ZCParamsDec;
}

class CMainParams : public CChainParams
{
public:
    CMainParams()
    {
        networkID = CBaseChainParams::MAIN;
        strNetworkID = "main";
        /**
         * The message start string is designed to be unlikely to occur in normal data.
         * The characters are rarely used upper ASCII, not valid as UTF-8, and produce
         * a large 4-byte int at any alignment.
         */
        pchMessageStart[0] = 0x44;
        pchMessageStart[1] = 0x34;
        pchMessageStart[2] = 0x52;
        pchMessageStart[3] = 0x4b;
        vAlertPubKey = ParseHex("044e12541a948e9967224bc6e6c587da44feee39d454812389ac5eaa084ddaf40d908c21b1fd89244eb021f19d9bd192f1a89a0d7c51880eb467a83cea0858271d");
        nDefaultPort = 6667;
bnProofOfWorkLimit = ~uint256(0) >> 20; // ~uint256(0) >> 1;
        nSubsidyHalvingInterval = 999999;
        nMaxReorganizationDepth = 100;
        nEnforceBlockUpgradeMajority = 750; // 75%
        nRejectBlockOutdatedMajority = 950; // 95%
        nToCheckBlockUpgradeMajority = 1000; // Approximate expected amount of blocks in 7 days (1440*7.5)
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // DARKPAYCOIN: 1 day
        nTargetSpacing = 1 * 60;  // DARKPAYCOIN: 1 minute
        nMaturity = 66;
        nMasternodeCountDrift = 20;
        nMaxMoneyOut = 10000000 * COIN;

        /** Height or Time Based Activations **/
        nLastPOWBlock = 266;
        nModifierUpdateBlock = 999999;
        nZerocoinStartHeight = 667;
        nZerocoinStartTime = 1536141951; // Sept 5, 10:05:51 AM
        nBlockEnforceSerialRange = 300006; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 306000; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 667; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 667; //Last valid accumulator checkpoint
        nBlockEnforceInvalidUTXO = 667; //Start enforcing the invalid UTXO's
        nInvalidAmountFiltered = 0*COIN; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 999999; //!> The block that zerocoin v2 becomes active - roughly Tuesday, May 8, 2018 4:00:00 AM GMT
        nEnforceNewSporkKey = 1925158000; //!> Sporks signed after (GMT): Tuesday, May 1, 2018 7:00:00 AM GMT must use the new spork key
        nRejectOldSporkKey = 1927811200; //!> Fully reject old spork key after (GMT): Friday, June 1, 2018 12:00:00 AM

        /**
         * Build the genesis block. Note that the output of the genesis coinbase cannot
         * be spent as it did not originally exist in the database.
         *
         * CBlock(hash=00000ffd590b14, ver=1, hashPrevBlock=00000000000000, hashMerkleRoot=e0028e, nTime=1390095618, nBits=1e0ffff0, nNonce=28917698, vtx=1)
         *   CTransaction(hash=e0028e, ver=1, vin.size=1, vout.size=1, nLockTime=0)
         *     CTxIn(COutPoint(000000, -1), coinbase 04ffff001d01044c5957697265642030392f4a616e2f3230313420546865204772616e64204578706572696d656e7420476f6573204c6976653a204f76657273746f636b2e636f6d204973204e6f7720416363657074696e6720426974636f696e73)
         *     CTxOut(nValue=50.00000000, scriptPubKey=0xA9037BAC7050C479B121CF)
         *   vMerkleTree: e0028e
         */
const char* pszTimestamp = "DarkPayCoin, just like LightPayCoin on steroids without the bullshit!";
        CMutableTransaction txNew;
        txNew.vin.resize(1);
        txNew.vout.resize(1);
        txNew.vin[0].scriptSig = CScript() << 486604799 << CScriptNum(4) << vector<unsigned char>((const unsigned char*)pszTimestamp, (const unsigned char*)pszTimestamp + strlen(pszTimestamp));
        txNew.vout[0].SetEmpty();
        genesis.vtx.push_back(txNew);
        genesis.hashPrevBlock = 0;
        genesis.hashMerkleRoot = genesis.BuildMerkleTree();
        genesis.nVersion = 1;
        genesis.nTime = 1536012000;
        genesis.nBits = 0x1e0ffff0;
        genesis.nNonce = 2189760;


        hashGenesisBlock = genesis.GetHash();

//// debug print
 //       printf("%s\n", genesis.GetHash().ToString().c_str());
 //       printf("%s\n", hashGenesisBlock.ToString().c_str(//       printf("%s\n", genesis.hashMerkleRoot.ToString().c_str());
//printf("%s\n", genesis.ToString().c_str());

        assert(hashGenesisBlock == uint256("0x00000d5bd64fbdfb201c8ebbf2c714a5321c3db9765ff69c482db9e4a609aa18"));
		assert(genesis.hashMerkleRoot == uint256("0xd8c2ab199e7591137447903741364e59cf4a5de55c687a784ed322c8940a5045"));

		vSeeds.push_back(CDNSSeedData("dns.darkpaycoin.io", "dns.darkpaycoin.io"));
		vSeeds.push_back(CDNSSeedData("explorer2.darkpaycoin.io", "explorer2.darkpaycoin.io"));
        vSeeds.push_back(CDNSSeedData("46.101.231.40", "46.101.231.40"));         
        vSeeds.push_back(CDNSSeedData("136.243.185.4", "136.243.185.4"));         
        vSeeds.push_back(CDNSSeedData("167.99.220.116", "167.99.220.116"));         
		vSeeds.push_back(CDNSSeedData("206.189.173.84", "206.189.173.84"));

		base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 30);
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 13);
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 212);
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x66)(0x2D)(0x25)(0x33).convert_to_container<std::vector<unsigned char> >();
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x66)(0x21)(0x31)(0x2B).convert_to_container<std::vector<unsigned char> >();
        // 	BIP44 coin type is from https://github.com/satoshilabs/slips/blob/master/slip-0044.md
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x01)(0xbc).convert_to_container<std::vector<unsigned char> >();


        convertSeed6(vFixedSeeds, pnSeed6_main, ARRAYLEN(pnSeed6_main));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = false;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fSkipProofOfWorkCheck = false;
        fTestnetToBeDeprecatedFieldRPC = false;
        fHeadersFirstSyncingActive = false;

        nPoolMaxTransactions = 3;
        strSporkKeyOld = "04B433E6598390C992F4F022F20D3B4CBBE691652EE7C48243B81701CBDB7CC7D7BF0EE09E154E6FCBF2043D65AF4E9E97B89B5DBAF830D83B9B7F469A6C45A717";
        strSporkKey = "0497aa980ee613f3b9b88602e342c80cdf33952efcb62831824d8ec9b4f75bc7c57ed8124804d24fb164eb1fef2ab861ba6fe8b16caa9de59c804ca6159fa23a97";
		strObfuscationPoolDummyAddress = "DFKwzU7as59Cgqv7LWqbeH23Wnm8wTxMvU";
        nStartMasternodePayments = 1536141951; //Wed, 25 Jun 2014 20:36:16 GMT

        /** Zerocoin */
        /** Zerocoin */
        zerocoinModulus = "25195908475657893494027183240048398571429282126204032027777137836043662020707595556264018525880784"
            "4069182906412495150821892985591491761845028084891200728449926873928072877767359714183472702618963750149718246911"
            "6507761337985909570009733045974880842840179742910064245869181719511874612151517265463228221686998754918242243363"
            "7259085141865462043576798423387184774447920739934236584823824281198163815010674810451660377306056201619676256133"
            "8441436038339044149526344321901146575444541784240209246165157233507787077498171257724679629263863563732899121548"
			"31438167899885040445364023527381951378636564391212010397122822120720357";
        nMaxZerocoinSpendsPerTransaction = 7; // Assume about 20kb each
        nMinZerocoinMintFee = 1 * CENT; //high fee required for zerocoin mints
        nMintRequiredConfirmations = 20; //the maximum amount of confirmations until accumulated in 19
        nRequiredAccumulation = 1;
        nDefaultSecurityLevel = 100; //full security level for accumulators
        nZerocoinHeaderVersion = 4; //Block headers must be this version once zerocoin is active
        nZerocoinRequiredStakeDepth = 200; //The required confirmations for a zdkpc to be stakable

        nBudget_Fee_Confirmations = 6; // Number of confirmations for the finalization fee
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return data;
    }
};
static CMainParams mainParams;

/**
 * Testnet (v3)
 */
class CTestNetParams : public CMainParams
{
public:
    CTestNetParams()
    {
        networkID = CBaseChainParams::TESTNET;
        strNetworkID = "test";
        pchMessageStart[0] = 0x45;
        pchMessageStart[1] = 0x76;
        pchMessageStart[2] = 0x65;
        pchMessageStart[3] = 0xba;
        vAlertPubKey = ParseHex("000010e83b2703ccf322f7dbd62dd5855ac7c10bd055814ce121ba32607d573b8810c02c0582aed05b4deb9c4b77b26d92428c61256cd42774babea0a073b2ed0c9");
        nDefaultPort = 51474;
        nEnforceBlockUpgradeMajority = 4320; // 75%
        nRejectBlockOutdatedMajority = 5472; // 95%
        nToCheckBlockUpgradeMajority = 5760; // 4 days
        nMinerThreads = 0;
        nTargetTimespan = 1 * 60; // DARKPAYCOIN: 1 day
        nTargetSpacing = 1 * 60;  // DARKPAYCOIN: 1 minute
        nLastPOWBlock = 200;
        nMaturity = 15;
        nMasternodeCountDrift = 4;
        nModifierUpdateBlock = 51197; //approx Mon, 17 Apr 2017 04:00:00 GMT
        nMaxMoneyOut = 43199500 * COIN;
        nZerocoinStartHeight = 201576;
        nZerocoinStartTime = 1501776000;
        nBlockEnforceSerialRange = 1; //Enforce serial range starting this block
        nBlockRecalculateAccumulators = 9908000; //Trigger a recalculation of accumulators
        nBlockFirstFraudulent = 9891737; //First block that bad serials emerged
        nBlockLastGoodCheckpoint = 9891730; //Last valid accumulator checkpoint
        nBlockEnforceInvalidUTXO = 9902850; //Start enforcing the invalid UTXO's
        nInvalidAmountFiltered = 0; //Amount of invalid coins filtered through exchanges, that should be considered valid
        nBlockZerocoinV2 = 444020; //!> The block that zerocoin v2 becomes active
        nEnforceNewSporkKey = 1521604800; //!> Sporks signed after Wednesday, March 21, 2018 4:00:00 AM GMT must use the new spork key
        nRejectOldSporkKey = 1522454400; //!> Reject old spork key after Saturday, March 31, 2018 12:00:00 AM GMT

        //! Modify the testnet genesis block so the timestamp is valid for a later start.
        genesis.nTime = 1454124731;
        genesis.nNonce = 2402015;

        hashGenesisBlock = genesis.GetHash();
        //assert(hashGenesisBlock == uint256("0x0000041e482b9b9691d98eefb48473405c0b8ec31b76df3797c74a78680ef818"));

        vFixedSeeds.clear();
        vSeeds.clear();
        vSeeds.push_back(CDNSSeedData("fuzzbawls.pw", "darkpaycoin-testnet.seed.fuzzbawls.pw"));
        vSeeds.push_back(CDNSSeedData("fuzzbawls.pw", "darkpaycoin-testnet.seed2.fuzzbawls.pw"));
        vSeeds.push_back(CDNSSeedData("s3v3nh4cks.ddns.net", "s3v3nh4cks.ddns.net"));
        vSeeds.push_back(CDNSSeedData("88.198.192.110", "88.198.192.110"));

        base58Prefixes[PUBKEY_ADDRESS] = std::vector<unsigned char>(1, 139); // Testnet darkpaycoin addresses start with 'x' or 'y'
        base58Prefixes[SCRIPT_ADDRESS] = std::vector<unsigned char>(1, 19);  // Testnet darkpaycoin script addresses start with '8' or '9'
        base58Prefixes[SECRET_KEY] = std::vector<unsigned char>(1, 239);     // Testnet private keys start with '9' or 'c' (Bitcoin defaults)
        // Testnet darkpaycoin BIP32 pubkeys start with 'DRKV'
        base58Prefixes[EXT_PUBLIC_KEY] = boost::assign::list_of(0x3a)(0x80)(0x61)(0xa0).convert_to_container<std::vector<unsigned char> >();
        // Testnet darkpaycoin BIP32 prvkeys start with 'DRKP'
        base58Prefixes[EXT_SECRET_KEY] = boost::assign::list_of(0x3a)(0x80)(0x58)(0x37).convert_to_container<std::vector<unsigned char> >();
        // Testnet darkpaycoin BIP44 coin type is '1' (All coin's testnet default)
        base58Prefixes[EXT_COIN_TYPE] = boost::assign::list_of(0x80)(0x00)(0x00)(0x01).convert_to_container<std::vector<unsigned char> >();

        convertSeed6(vFixedSeeds, pnSeed6_test, ARRAYLEN(pnSeed6_test));

        fMiningRequiresPeers = true;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = false;
        fRequireStandard = true;
        fMineBlocksOnDemand = false;
        fTestnetToBeDeprecatedFieldRPC = true;

        nPoolMaxTransactions = 2;
        strSporkKey = "04A8B319388C0F8588D238B9941DC26B26D3F9465266B368A051C5C100F79306A557780101FE2192FE170D7E6DEFDCBEE4C8D533396389C0DAFFDBC842B002243C";
        strSporkKeyOld = "04348C2F50F90267E64FACC65BFDC9D0EB147D090872FB97ABAE92E9A36E6CA60983E28E741F8E7277B11A7479B626AC115BA31463AC48178A5075C5A9319D4A38";
        strObfuscationPoolDummyAddress = "y57cqfGRkekRyDRNeJiLtYVEbvhXrNbmox";
        nStartMasternodePayments = 1420837558; //Fri, 09 Jan 2015 21:05:58 GMT
        nBudget_Fee_Confirmations = 3; // Number of confirmations for the finalization fee. We have to make this very short
                                       // here because we only have a 8 block finalization window on testnet
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataTestnet;
    }
};
static CTestNetParams testNetParams;

/**
 * Regression test
 */
class CRegTestParams : public CTestNetParams
{
public:
    CRegTestParams()
    {
        networkID = CBaseChainParams::REGTEST;
        strNetworkID = "regtest";
        strNetworkID = "regtest";
        pchMessageStart[0] = 0xa1;
        pchMessageStart[1] = 0xcf;
        pchMessageStart[2] = 0x7e;
        pchMessageStart[3] = 0xac;
        nSubsidyHalvingInterval = 150;
        nEnforceBlockUpgradeMajority = 750;
        nRejectBlockOutdatedMajority = 950;
        nToCheckBlockUpgradeMajority = 1000;
        nMinerThreads = 1;
        nTargetTimespan = 24 * 60 * 60; // DARKPAYCOIN: 1 day
        nTargetSpacing = 1 * 60;        // DARKPAYCOIN: 1 minutes
        bnProofOfWorkLimit = ~uint256(0) >> 1;
        genesis.nTime = 1454124731;
        genesis.nBits = 0x207fffff;
        genesis.nNonce = 12345;

        hashGenesisBlock = genesis.GetHash();
        nDefaultPort = 51476;
        //assert(hashGenesisBlock == uint256("0x4f023a2120d9127b21bbad01724fdb79b519f593f2a85b60d3d79160ec5f29df"));

        vFixedSeeds.clear(); //! Testnet mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Testnet mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fAllowMinDifficultyBlocks = true;
        fDefaultConsistencyChecks = true;
        fRequireStandard = false;
        fMineBlocksOnDemand = true;
        fTestnetToBeDeprecatedFieldRPC = false;
    }
    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        return dataRegtest;
    }
};
static CRegTestParams regTestParams;

/**
 * Unit test
 */
class CUnitTestParams : public CMainParams, public CModifiableParams
{
public:
    CUnitTestParams()
    {
        networkID = CBaseChainParams::UNITTEST;
        strNetworkID = "unittest";
        nDefaultPort = 51478;
        vFixedSeeds.clear(); //! Unit test mode doesn't have any fixed seeds.
        vSeeds.clear();      //! Unit test mode doesn't have any DNS seeds.

        fMiningRequiresPeers = false;
        fDefaultConsistencyChecks = true;
        fAllowMinDifficultyBlocks = false;
        fMineBlocksOnDemand = true;
    }

    const Checkpoints::CCheckpointData& Checkpoints() const
    {
        // UnitTest share the same checkpoints as MAIN
        return data;
    }

    //! Published setters to allow changing values in unit test cases
    virtual void setSubsidyHalvingInterval(int anSubsidyHalvingInterval) { nSubsidyHalvingInterval = anSubsidyHalvingInterval; }
    virtual void setEnforceBlockUpgradeMajority(int anEnforceBlockUpgradeMajority) { nEnforceBlockUpgradeMajority = anEnforceBlockUpgradeMajority; }
    virtual void setRejectBlockOutdatedMajority(int anRejectBlockOutdatedMajority) { nRejectBlockOutdatedMajority = anRejectBlockOutdatedMajority; }
    virtual void setToCheckBlockUpgradeMajority(int anToCheckBlockUpgradeMajority) { nToCheckBlockUpgradeMajority = anToCheckBlockUpgradeMajority; }
    virtual void setDefaultConsistencyChecks(bool afDefaultConsistencyChecks) { fDefaultConsistencyChecks = afDefaultConsistencyChecks; }
    virtual void setAllowMinDifficultyBlocks(bool afAllowMinDifficultyBlocks) { fAllowMinDifficultyBlocks = afAllowMinDifficultyBlocks; }
    virtual void setSkipProofOfWorkCheck(bool afSkipProofOfWorkCheck) { fSkipProofOfWorkCheck = afSkipProofOfWorkCheck; }
};
static CUnitTestParams unitTestParams;


static CChainParams* pCurrentParams = 0;

CModifiableParams* ModifiableParams()
{
    assert(pCurrentParams);
    assert(pCurrentParams == &unitTestParams);
    return (CModifiableParams*)&unitTestParams;
}

const CChainParams& Params()
{
    assert(pCurrentParams);
    return *pCurrentParams;
}

CChainParams& Params(CBaseChainParams::Network network)
{
    switch (network) {
    case CBaseChainParams::MAIN:
        return mainParams;
    case CBaseChainParams::TESTNET:
        return testNetParams;
    case CBaseChainParams::REGTEST:
        return regTestParams;
    case CBaseChainParams::UNITTEST:
        return unitTestParams;
    default:
        assert(false && "Unimplemented network");
        return mainParams;
    }
}

void SelectParams(CBaseChainParams::Network network)
{
    SelectBaseParams(network);
    pCurrentParams = &Params(network);
}

bool SelectParamsFromCommandLine()
{
    CBaseChainParams::Network network = NetworkIdFromCommandLine();
    if (network == CBaseChainParams::MAX_NETWORK_TYPES)
        return false;

    SelectParams(network);
    return true;
}
