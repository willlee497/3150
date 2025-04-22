#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <openssl/sha.h>
#include <chrono>
#include <sstream>
#include <iomanip>
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>

class NfToken {
public:
    explicit NfToken(const std::string& assetName) : _name(assetName) {
        auto now = std::chrono::high_resolution_clock::now().time_since_epoch().count();
        std::string data = _name + std::to_string(now);
        unsigned char hash[SHA256_DIGEST_LENGTH];
        SHA256(reinterpret_cast<const unsigned char*>(data.data()), data.size(), hash);
        std::ostringstream oss;
        for (auto b : hash) {
            oss << std::hex << std::setw(2) << std::setfill('0') << static_cast<int>(b);
        }
        _id = oss.str();
    }

    const std::string& name() const { return _name; }
    const std::string& id() const { return _id; }

private:
    std::string _name;
    std::string _id;
};

class ManageTokens {
public:
    void mintToken(const std::string& assetName, size_t walletIndex = 0) {
        auto token = std::make_unique<NfToken>(assetName);
        getWallet(walletIndex).push_back(std::move(token));
    }

    void transferToken(size_t from, size_t to, size_t tokenIndex) {
        auto& src = getWallet(from);
        auto& dst = getWallet(to);
        if (from == to || tokenIndex >= src.size()) {
            throw std::out_of_range("Invalid transfer");
        }
        dst.push_back(std::move(src[tokenIndex]));
        src.erase(src.begin() + tokenIndex);
    }

    size_t walletSize(size_t idx) const { return getWallet(idx).size(); }
    const NfToken* getToken(size_t wi, size_t ti) const { return getWallet(wi).at(ti).get(); }

private:
    std::vector<std::unique_ptr<NfToken>> wallet1, wallet2;

    std::vector<std::unique_ptr<NfToken>>& getWallet(size_t i) {
        return (i == 0 ? wallet1 : wallet2);
    }
    const std::vector<std::unique_ptr<NfToken>>& getWallet(size_t i) const {
        return (i == 0 ? wallet1 : wallet2);
    }
};

TEST_CASE("Minting and transferring NFTs") {
    ManageTokens manager;
    manager.mintToken("CryptoKitty", 0);
    manager.mintToken("CryptoPunk", 0);

    CHECK(manager.walletSize(0) == 2);
    CHECK(manager.getToken(0, 0)->name() == "CryptoKitty");
    CHECK(manager.getToken(0, 1)->name() == "CryptoPunk");

    manager.transferToken(0, 1, 0);
    CHECK(manager.walletSize(0) == 1);
    CHECK(manager.walletSize(1) == 1);
    CHECK(manager.getToken(1, 0)->name() == "CryptoKitty");

    std::cout << "Minting and transferring tests completed successfully." << std::endl;
}
