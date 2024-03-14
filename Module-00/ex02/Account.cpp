/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: panger <panger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 13:19:12 by panger            #+#    #+#             */
/*   Updated: 2024/03/14 16:40:28 by panger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>

int Account::t::_totalAmount = 0;
int Account::t::_nbAccounts = 0;
int Account::t::_totalNbDeposits = 0;
int Account::t::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) {
	this->_accountIndex = this->_nbAccounts;
	this->_amount = initial_deposit;
	this->_nbDeposits = 0;
	Account::_totalAmount += initial_deposit;
	Account::_nbAccounts += 1;
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created\n";
}

Account::~Account(void)
{
	this->_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed\n";
	Account::_nbAccounts -= 1;
}

void	Account::makeDeposit(int deposit)
{
	this->_nbDeposits += 1;
	Account::_totalNbDeposits += 1;
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";deposit:" << deposit << ";amount:" << this->_amount + deposit << ";nb_deposits:" << this->_nbDeposits << "\n";
	this->_amount += deposit;
	Account::_totalAmount += deposit;
}

bool	Account::makeWithdrawal(int withdrawal)
{
	if (this->_amount > withdrawal)
	{
		this->_nbWithdrawals += 1;
		Account::_totalNbWithdrawals += 1;
		Account::_displayTimestamp();
		std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:" << withdrawal << ";amount:" << this->_amount - withdrawal << ";nb_withdrawals:" << this->_nbWithdrawals << "\n";
		this->_amount -= withdrawal;
		Account::_totalAmount -= withdrawal;
		return (true);
	}
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";p_amount:" << this->_amount << ";withdrawal:refused\n";
	return (false);
}

int Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

void	Account::displayAccountsInfos(void)
{
	Account::_displayTimestamp();
	std::cout << "accounts:" << Account::_nbAccounts << ";total:" << Account::_totalAmount << ";deposits:" << Account::_totalNbDeposits << ";withdrawals:" << Account::_totalNbWithdrawals << "\n";
}

int	Account::checkAmount() const
{
	return (this->_amount);
}

void	Account::displayStatus(void) const
{
	Account::_displayTimestamp();
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";deposits:" << this->_nbDeposits << ";withdrawals:" << this->_nbWithdrawals << "\n";
}

void	Account::_displayTimestamp(void)
{
	std::time_t rawtime = std::time(nullptr);
    std::tm* timeinfo = std::localtime(&rawtime);
    std::ostringstream oss;
    oss << std::put_time(timeinfo, "%Y%m%d_%H%M%S");
    std::string formatted_time = oss.str();
    std::cout << "[" << formatted_time << "] ";
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}