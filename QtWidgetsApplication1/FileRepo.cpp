//
//ostream& operator<<(ostream& out, const RepositoryExceptions& ex) {
//	for (const auto& m : ex.mesage)
//		out << m;
//	return out;
//}
//
//void ProductRepositoryFile::loadfromfile() {
//	std::ifstream in(fName);
//	if (!in.is_open()) { //verify if the stream is opened		
//		throw RepositoryExceptions("Unable to open file:" + fName);
//	}
//	while (!in.eof()) {
//		string name;
//		in >> name;
//		int price;
//		in >> price;
//		string type;
//		in >> type;
//		string producer;
//		in >> producer;
//
//		if (in.eof()) {	//nu am reusit sa citesc numarul
//			break;
//		}
//		Product p{ name, price, type, producer };
//		ProductRepository::addRepo(p);
//	}
//	in.close();
//}
//
//void ProductRepositoryFile::savetofile() {
//	std::ofstream out(fName);
//	if (!out.is_open()) { //verify if the stream is opened
//		std::string msg("Unable to open file:");
//		throw RepositoryExceptions(msg);
//	}
//	for (auto& p : ProductRepository::getAllR()) {
//		out << p.getName();
//		out << endl;
//		out << p.getPrice();
//		out << endl;
//		out << p.getType();
//		out << endl;
//		out << p.getProducer();
//		out << endl;
//	}
//	out.close();
//}
