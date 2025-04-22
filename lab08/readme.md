# NFT Lab

## Overview
This project demonstrates the minting and transferring of non-fungible tokens (NFTs) using C++. It showcases the use of smart pointers (`unique_ptr`) and cryptographic hashes (SHA-256) to manage and uniquely identify digital assets in a blockchain-like system.

## Compilation Instructions
To compile the project, use the following command:
g++ NfToken.cpp -lcrypto -std=c++17 -o nft_lab && ./nft_lab


## Running Tests
To execute unit tests, ensure that `doctest.h` is in your include path and compile the program with the test definitions included.

