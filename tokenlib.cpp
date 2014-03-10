#include "tokenlib.h"

#include <algorithm>
#include <iostream>
#include <iterator>
#include <exception>
#include <string>
#include <vector>
#include <set>
#include <stdexcept> 

//#export LD_LIBRARY_PATH=./tokenlib

namespace tokenlib {

// Various static stuff that the outside world should not see
static std::size_t nr_of_generated_tokens = 20;
static std::vector<int> generated_tokens(nr_of_generated_tokens);
static std::set<int> acquired_tokens;
static bool tokens_initialised = false;

void initialise_tokens(void)
{
	// Fill the token vector with values 0,...,n-1
	// Shuffle them too
	std::size_t n = 100;
	std::generate(generated_tokens.begin(), generated_tokens.end(),
		[&]{ return n++; }); 
	std::random_shuffle(generated_tokens.begin(), generated_tokens.end());

	// Clear the acquired tokens set
	acquired_tokens.clear();

	tokens_initialised = true;
}


int acquire_token(void)
{
	// Initialise tokens if necessary
	if(!tokens_initialised)
		{ initialise_tokens(); }

	// Fall over if they've really run out of tokens
	if(generated_tokens.empty())
		{ throw std::runtime_error("Out of tokens"); }

	// Pull the last token off the back of the vector
	// Put it in the set of acquired tokens
	// Return to the user
	int token = std::move(generated_tokens.back());
	generated_tokens.pop_back();
	acquired_tokens.insert(token);
	return token;
}

void release_token(int token)
{
	// Fall over if they try release a token they haven't acquired.
	if(acquired_tokens.count(token) == 0)
	{
		throw std::runtime_error(
			std::string("Attempting to release unacquired token ") +
			std::to_string(token));
	}

	acquired_tokens.erase(token);
	generated_tokens.push_back(token);
}

void check_tokens(void)
{
	std::cout << "Acquired Tokens: ";
	std::copy(acquired_tokens.begin(), acquired_tokens.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

	std::cout << "Token Pool: ";
	std::copy(generated_tokens.begin(), generated_tokens.end(),
		std::ostream_iterator<int>(std::cout, " "));
	std::cout << std::endl;

}

void final_token_check(void)
{
	if(acquired_tokens.size() == 0 &&
		generated_tokens.size() == nr_of_generated_tokens)
	{
		std::cout << "SUCCESS: All acquired tokens have been released" << std::endl;
	}
	else
	{
		std::cout << "FAILURE: Not all tokens have been released" << std::endl;
		check_tokens();
	}
}

} // namespace
