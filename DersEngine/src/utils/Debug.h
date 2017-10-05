#pragma once

#include <iostream>
#include <string>
#include <vector>

namespace engine
{
	namespace debug
	{
		struct any
		{
			enum type { Int, Size_t, Float, Double, String, Bool };

			any(int e) { m_Data.INT = e; m_Type = Int; }
			any(std::size_t e) { m_Data.SIZE_T = e; m_Type = Size_t; }
			any(float e) { m_Data.FLOAT = e; m_Type = Float; }
			any(double e) { m_Data.DOUBLE = e; m_Type = Double; }
			any(const char* e) { m_Data.STRING = e; m_Type = String; }
			any(bool e) { m_Data.BOOL = e; m_Type = Bool; }

			inline type get_type() const { return m_Type; }

			inline int get_int() const { return m_Data.INT; }
			inline std::size_t get_size() const { return m_Data.SIZE_T; }
			inline float get_float() const { return m_Data.FLOAT; }
			inline double get_double() const { return m_Data.DOUBLE; }
			inline const char* get_string() const { return m_Data.STRING; }
			inline bool get_bool() const { return m_Data.BOOL; }

		private:
			type m_Type;

			union {
				int INT;
				std::size_t SIZE_T;
				float FLOAT;
				double DOUBLE;
				const char* STRING;
				bool BOOL;
			} m_Data;
		};

		template <class ...Args>
		void LogImplementation(const Args&... args)
		{
			std::vector<any> paramList = { args... };

			for (const auto& elem : paramList)
			{
				switch (elem.get_type())
				{
				case any::Int:
					std::cout << elem.get_int();
					break;
				case any::Size_t:
					std::cout << elem.get_size();
					break;
				case any::Float:
					std::cout << elem.get_float();
					break;
				case any::Double:
					std::cout << elem.get_double();
					break;
				case any::String:
					std::cout << elem.get_string();
					break;
				case any::Bool:
				{
					if (elem.get_bool() == 1)
					{
						std::cout << "true";
					}
					else
					{
						std::cout << "false";
					}
				}
				break;
				}
			}

			std::cout << "\n";
		}

		template <class ...Args>
		static void Log(Args... args)
		{
			LogImplementation(any(args)...);
		}
	}
}