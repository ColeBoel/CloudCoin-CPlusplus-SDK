#pragma once

#include "BankKeys.h"
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
#include <stdexcept>
#include <curl.h>
#include "Interpretation.h"
#include "Receipt.h"

using namespace std;


	class CloudBankUtils
	{
	private:
		//BankKeys *keys;
		BankKeys keys;
		string rawStackForDeposit;
		string rawStackFromWithdrawal;
		string receiptNumber;
	public:
		int onesInBank = 0;
		int fivesInBank = 0;
		int twentyFivesInBank = 0;
		int hundresInBank = 0;
		int twohundredfiftiesInBank = 0;
		int totalCoinsWithdrawn = 0;
		string rawReceipt;
		

		/*
		virtual CloudBankUtils()
		{
			delete keys;
			delete cli;
		}
		*/

		CloudBankUtils(BankKeys startKeys);

		void showCoins();
		

		void loadStackFromFile(const std::wstring &filename);
	
		
		void sendStackToCloudBank(const std::string &toPublicURL);

		void getReceipt(string toPublicURL);

		void getStackFromCloudBank(int amountToWithdraw);


	private:
		

	public:

		Interpretation interpretReceipt();

		void saveStackToFile(string path);

		std::string getStackName();

		void transferCloudCoins(string toPublicKey, int coinsToSend);

		int getDenomination(int sn);

	};
