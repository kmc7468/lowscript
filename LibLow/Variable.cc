#include "LibLow/Variable.hh"

#include "LibLow/Types/Bool.hh"
#include "LibLow/Types/Double.hh"
#include "LibLow/Types/Int.hh"

namespace LibLow
{
	Variable::Variable(const std::string& name, const Type& type)
		: Variable(name, type, TypeOption::None)
	{}
	Variable::Variable(const std::string& name, const Type& type, const LibLow::TypeOption& type_option)
		: Name_(name), TypeOption_(type_option)
	{
		switch (type)
		{
		case Type::Bool:
		{
			Value_ = Types::Bool::Create();
			break;
		}

		case Type::Double:
		{
			Value_ = Types::Double::Create();
			break;
		}

		case Type::Int:
		{
			Value_ = Types::Int::Create();
			break;
		}

		default:
			throw "A type that cannot be instantiated.";
		}
	}

	const Object::Ptr Variable::Value() const
	{
		return Value_;
	}
	Object::Ptr Variable::Value()
	{
		return Value_;
	}
	TypeOption Variable::TypeOption() const noexcept
	{
		return TypeOption_;
	}
	std::string Variable::Name() const
	{
		return Name_;
	}
}