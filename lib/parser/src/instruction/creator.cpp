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
    m_creators.push_back(
        [](const std::string& value) { return CreateInstruction<PutCommand>()(value); });
    m_creators.push_back(
        [](const std::string& value) { return CreateInstruction<PopCommand>()(value); });
    m_creators.push_back(
        [](const std::string& value) { return CreateInstruction<AddCommand>()(value); });
    m_creators.push_back(
        [](const std::string& value) { return CreateInstruction<SubCommand>()(value); });
    m_creators.push_back(
        [](const std::string& value) { return CreateInstruction<MulCommand>()(value); });
    m_creators.push_back(
        [](const std::string& value) { return CreateInstruction<DivCommand>()(value); });
    m_creators.push_back(
        [](const std::string& value) { return CreateInstruction<ModCommand>()(value); });
    m_creators.push_back(
        [](const std::string& value) { return CreateInstruction<EndCommand>()(value); });
    m_creators.push_back(
        [](const std::string& value) { return CreateInstruction<AssertCommand>()(value); });
    m_creators.push_back(
        [](const std::string& value) { return CreateInstruction<PrintCommand>()(value); });
    m_creators.push_back(
        [](const std::string& value) { return CreateInstruction<TraceCommand>()(value); });
}

const ICommand* InstructionCreator::create(eInstruction type, const std::string& value)
{
    return m_creators[static_cast<int>(type)](value);
}

}  // namespace instructions
}  // namespace parsing
}  // namespace elemvm
