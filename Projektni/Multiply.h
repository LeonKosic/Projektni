#pragma once
namespace Graph {
	template<typename T> class Multiply :Operation<T> {
	private:
	public:
		T calculate() const override {
			if (empty())throw std::exception("Nema validnih operanada za izvrsavanje operacije");
			try {
				T res(operands[0]);
				for (int i = 1; i < operands.size(); i++) {
					for (int j = 0; j < res.size(); j++) {
						res[j] *= operands[i][j];
					}
				}
				return res;
			}
			catch (std::exception& e) {
				std::cout << e.what();
			}
		}
	};
}