/*
g++ -E -P -o test_hello.i test_hello.cpp
clang-format -i --style=Microsoft test_hello.i
*/

static_assert(sizeof("HelloTest") > 1, "test_suite_name must not be empty");
static_assert(sizeof("BasicAssertions") > 1, "test_name must not be empty");
class HelloTest_BasicAssertions_Test : public ::testing::Test
{
  public:
    HelloTest_BasicAssertions_Test() = default;
    ~HelloTest_BasicAssertions_Test() override = default;
    HelloTest_BasicAssertions_Test(const HelloTest_BasicAssertions_Test &) = delete;
    HelloTest_BasicAssertions_Test &operator=(const HelloTest_BasicAssertions_Test &) = delete;
    HelloTest_BasicAssertions_Test(HelloTest_BasicAssertions_Test &&) noexcept = delete;
    HelloTest_BasicAssertions_Test &operator=(HelloTest_BasicAssertions_Test &&) noexcept = delete;

  private:
    void TestBody() override;
    static ::testing::TestInfo *const test_info_ __attribute__((unused));
};
::testing::TestInfo *const HelloTest_BasicAssertions_Test::test_info_ = ::testing::internal::MakeAndRegisterTestInfo(
    "HelloTest", "BasicAssertions", nullptr, nullptr, ::testing::internal::CodeLocation("test_hello.cpp", 42),
    (::testing::internal::GetTestTypeId()),
    ::testing::internal::SuiteApiResolver<::testing::Test>::GetSetUpCaseOrSuite("test_hello.cpp", 42),
    ::testing::internal::SuiteApiResolver<::testing::Test>::GetTearDownCaseOrSuite("test_hello.cpp", 42),
    new ::testing::internal::TestFactoryImpl<HelloTest_BasicAssertions_Test>);
void HelloTest_BasicAssertions_Test::TestBody()
{
    switch (0)
    case 0:
    default:
        if (const ::testing::AssertionResult gtest_ar =
                (::testing::internal::CmpHelperSTRNE("\"hello\"", "\"world\"", "hello", "world")))
            ;
        else
            ::testing::internal::AssertHelper(::testing::TestPartResult::kNonFatalFailure, "test_hello.cpp", 44,
                                              gtest_ar.failure_message()) = ::testing::Message();
    switch (0)
    case 0:
    default:
        if (const ::testing::AssertionResult gtest_ar =
                (::testing::internal::EqHelper::Compare("7 * 6", "42", 7 * 6, 42)))
            ;
        else
            ::testing::internal::AssertHelper(::testing::TestPartResult::kNonFatalFailure, "test_hello.cpp", 46,
                                              gtest_ar.failure_message()) = ::testing::Message();
}
