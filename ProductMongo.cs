using MongoDB.Bson;
using MongoDB.Driver;
using MongoDB.Driver.Core.Configuration;
using MySqlX.XDevAPI;
using Org.BouncyCastle.Utilities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PAWProiectFinal
{
    internal class ProductMongo
    {
        private readonly IMongoCollection<Produs> _collection;

        public ProductMongo(string connectionString, string databaseName, string collectionName)
        {
            var client = new MongoClient(connectionString);
            var database = client.GetDatabase(databaseName);
            _collection = database.GetCollection<Produs>(collectionName);
        }

        public List<Produs> GetProducts()
        {
            var products = _collection.Find(_ => true).ToList();
            return products;
        }

        public void AddProduct(Produs product, string connectionString, string _databaseName, string _collectionName)
        {
            var client = new MongoClient(connectionString);
            IMongoDatabase _database = client.GetDatabase(_databaseName);
            var collection = _database.GetCollection<BsonDocument>(_collectionName);

            var document = new BsonDocument
        {
            { "Nume", product.Nume },
            { "Cantitate", product.Cantitate },
            { "Pret", product.Pret }
        };

            collection.InsertOne(document);
        }

        public void RemoveProductById(string id, string connectionString, string _databaseName, string _collectionName)
        {
            var client = new MongoClient(connectionString);
            IMongoDatabase _database = client.GetDatabase(_databaseName);
            var collection = _database.GetCollection<BsonDocument>(_collectionName);

            var filter = Builders<BsonDocument>.Filter.Eq("_id", ObjectId.Parse(id));

            collection.DeleteOne(filter);
        }

        public void UpdateProductById(string id, string nume, int cantitate, int pret, string connectionString, string _databaseName, string _collectionName)
        {
            var client = new MongoClient(connectionString);
            IMongoDatabase _database = client.GetDatabase(_databaseName);
            var collection = _database.GetCollection<BsonDocument>(_collectionName);

            var filter = Builders<BsonDocument>.Filter.Eq("_id", ObjectId.Parse(id));
            var update = Builders<BsonDocument>.Update
                .Set("Nume", nume)
                .Set("Cantitate", cantitate)
                .Set("Pret", pret);

            collection.UpdateOne(filter, update);
        }

        public List<Produs> GetAllProducts(string connectionString, string _databaseName, string _collectionName)
        {
            var client = new MongoClient(connectionString);
            IMongoDatabase _database = client.GetDatabase(_databaseName);
            var collection = _database.GetCollection<BsonDocument>(_collectionName);

            var documents = collection.Find(new BsonDocument()).ToList();
            var productList = new List<Produs>();

            foreach (var document in documents)
            {
                var product = new Produs
                {
                    _id = document["_id"].ToString(),
                    Nume = document["Nume"].ToString(),
                    Cantitate = document["Cantitate"].ToInt32(),
                    Pret = document["Pret"].ToInt32()
                };

                productList.Add(product);
            }

            return productList;
        }

    }
}
