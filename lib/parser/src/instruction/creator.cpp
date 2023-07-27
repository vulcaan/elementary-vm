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
        [this](const std::string& value) { return CreateInstruction<PutCommand>()(value); });
    m_creators.push_back(
        [this](const std::string& value) { return CreateInstruction<PopCommand>()(value); });
    m_creators.push_back(
        [this](const std::string& value) { return CreateInstruction<AddCommand>()(value); });
    m_creators.push_back(
        [this](const std::string& value) { return CreateInstruction<SubCommand>()(value); });
    m_creators.push_back(
        [this](const std::string& value) { return CreateInstruction<MulCommand>()(value); });
    m_creators.push_back(
        [this](const std::string& value) { return CreateInstruction<DivCommand>()(value); });
    m_creators.push_back(
        [this](const std::string& value) { return CreateInstruction<ModCommand>()(value); });
    m_creators.push_back(
        [this](const std::string& value) { return CreateInstruction<EndCommand>()(value); });
    m_creators.push_back(
        [this](const std::string& value) { return CreateInstruction<AssertCommand>()(value); });
}
const ICommand* InstructionCreator::create(eInstruction type, const std::string& value)
{
    return m_creators[static_cast<int>(type)](value);
}

// const ICommand* InstructionCreator::createPut(const std::string& value) const
// {
// }
// const ICommand* InstructionCreator::createPop(const std::string& value) const
// {
// }
// const ICommand* InstructionCreator::createAdd(const std::string& value) const
// {
// }
// const ICommand* InstructionCreator::createSub(const std::string& value) const
// {
// }
// const ICommand* InstructionCreator::createMul(const std::string& value) const
// {
// }
// const ICommand* InstructionCreator::createDiv(const std::string& value) const
// {
// }
// const ICommand* InstructionCreator::createMod(const std::string& value) const
// {
// }
// const ICommand* InstructionCreator::createEnd(const std::string& value) const
// {
// }
// const ICommand* InstructionCreator::createAssert(const std::string& value) const
// {
// }
}  // namespace instructions
}  // namespace parsing

}  // namespace elemvm
