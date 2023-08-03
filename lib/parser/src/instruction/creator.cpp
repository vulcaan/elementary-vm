#include "instruction/creator.hpp"

#include "instruction/commands.hpp"
namespace elemvm
{
namespace parsing
{
namespace instructions
{

const ICommand* InstructionCreator::create(eInstruction type, const std::string& value)
{
    switch (type)
    {
    case eInstruction::PUT:
        return CreateInstruction<PutCommand>()(value);
    case eInstruction::POP:
        return CreateInstruction<PopCommand>()(value);
    case eInstruction::ADD:
        return CreateInstruction<AddCommand>()(value);
    case eInstruction::SUB:
        return CreateInstruction<SubCommand>()(value);
    case eInstruction::MUL:
        return CreateInstruction<MulCommand>()(value);
    case eInstruction::DIV:
        return CreateInstruction<DivCommand>()(value);
    case eInstruction::MOD:
        return CreateInstruction<ModCommand>()(value);
    case eInstruction::END:
        return CreateInstruction<EndCommand>()(value);
    case eInstruction::ASSERT:
        return CreateInstruction<AssertCommand>()(value);
    case eInstruction::PRINT:
        return CreateInstruction<PrintCommand>()(value);
    case eInstruction::TRACE:
        return CreateInstruction<TraceCommand>()(value);
    default:
        throw std::logic_error("Unknown instruction type passed!");
    };
}

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
