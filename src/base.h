//
// Created by moss on 2/11/22.
//
#pragma once

#include <string>
#include <iostream>
#include <utility>
#include <vector>

namespace mycelium {
	void initialize_static_values();

	enum token_type {
		op,
		whitespace,
		grouping,
		keyword,
		word,
		num,
		invalid,
		newline
	};

	template<typename T>
	bool vector_contains(const std::vector<T> &vec, const T &con);

	class token {
	public:
		token_type type;
		std::string string;

		static std::vector<std::string> whitespace_strings;
		static std::vector<std::string> grouping_strings;
		static std::vector<std::string> keyword_strings;
		static std::vector<std::string> oper_strings;
		static std::vector<std::vector<std::string>> string_lists;
		static std::vector<std::string> strings;
		static std::vector<std::string> type_names;


	public:
		token(token_type type, std::string str) : type(type), string(std::move(str)) {}

		explicit token(std::string str) : string(std::move(str)) {
			this->type = find_type(str);
		}

		static token_type find_type(const std::string &string);
	};

	class type {
	public:
		const int code;
		const std::string name;
		const int size;

		type(int code, std::string name, int size) : code(code), name(name), size(size) {}


		static const type pointer;
		static const type integer;
		static const type character;
		static const type string;
		static const type list;
		static const type tuple;
		static const type oper;
		static const type array;
		static const type cstring;
		static const type token;
	};


	class list {
	private:
		void *storage;

	public:
		list(int length) {

		}
	};


	std::vector<std::string> string_split(const std::string &str, const std::vector<std::string> &spl);

	template <typename T>
	std::ostream& operator<<(std::ostream& os, const std::vector<T>& dt);
}