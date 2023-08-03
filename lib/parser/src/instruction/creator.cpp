#include "instruction/creator.hpp"

#include "instruction/commands.hpp"
namespace elemvm
{
namespace parsing
{
namespace instructions
{
InstructionCreator::InstructionCreator()
{
    m_creators = {
        [](const std::string& value) { return CreateInstruction<PutCommand>()(value); },
        [](const std::string& value) { return CreateInstruction<PopCommand>()(value); },
        [](const std::string& value) { return CreateInstruction<AddCommand>()(value); },
        [](const std::string& value) { return CreateInstruction<SubCommand>()(value); },
        [](const std::string& value) { return CreateInstruction<MulCommand>()(value); },
        [](const std::string& value) { return CreateInstruction<DivCommand>()(value); },
        [](const std::string& value) { return CreateInstruction<ModCommand>()(value); },
        [](const std::string& value) { return CreateInstruction<EndCommand>()(value); },
        [](const std::string& value) { return CreateInstruction<AssertCommand>()(value); },
        [](const std::string& value) { return CreateInstruction<PrintCommand>()(value); },
        [](const std::string& value) { return CreateInstruction<TraceCommand>()(value); },
    };
}

const ICommand* InstructionCreator::create(eInstruction type, const std::string& value)
{
    return m_creators[static_cast<int>(type)](value);
}

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
