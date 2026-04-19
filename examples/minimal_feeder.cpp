#include <FeederInterface.h>
#include <FeederServerInterface.h>

class MinimalFeeder final : public FeederInterface {
public:
    std::string feeder_name() const override { return "minimal-feeder"; }
};

int main() {
    MinimalFeeder feeder;
    return feeder.getApiVersion() > 0 ? 0 : 1;
}
