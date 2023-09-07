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
    internal class FisaConsumMongo
    {
        private readonly IMongoCollection<FisaConsum> _collection;

        public FisaConsumMongo(string connectionString, string databaseName, string collectionName)
        {
            var client = new MongoClient(connectionString);
            var database = client.GetDatabase(databaseName);
            _collection = database.GetCollection<FisaConsum>(collectionName);
        }

        public List<FisaConsum> GetProducts()
        {
            var products = _collection.Find(_ => true).ToList();
            return products;
        }

        public void AddConsum(FisaConsum product, string connectionString, string _databaseName, string _collectionName)
        {
            var client = new MongoClient(connectionString);
            IMongoDatabase _database = client.GetDatabase(_databaseName);
            var collection = _database.GetCollection<BsonDocument>(_collectionName);

            var document = new BsonDocument
        {
            { "Nume_Produs", product.Nume_Produs },
            { "Nume_Materie_Prima", product.Nume_Materie_Prima },
            { "Cantitate", product.Cantitate }
        };

            collection.InsertOne(document);
        }

        public void RemoveConsumById(string id, string connectionString, string _databaseName, string _collectionName)
        {
            var client = new MongoClient(connectionString);
            IMongoDatabase _database = client.GetDatabase(_databaseName);
            var collection = _database.GetCollection<BsonDocument>(_collectionName);

            var filter = Builders<BsonDocument>.Filter.Eq("_id", ObjectId.Parse(id));

            collection.DeleteOne(filter);
        }

        public void UpdateConsumById(string id, string numep, string numemp, int cantitate, string connectionString, string _databaseName, string _collectionName)
        {
            var client = new MongoClient(connectionString);
            IMongoDatabase _database = client.GetDatabase(_databaseName);
            var collection = _database.GetCollection<BsonDocument>(_collectionName);

            var filter = Builders<BsonDocument>.Filter.Eq("_id", ObjectId.Parse(id));
            var update = Builders<BsonDocument>.Update
                .Set("Nume_Produs", numep)
                .Set("Nume_Materie_Prima", numemp)
                .Set("Cantitate", cantitate);

            collection.UpdateOne(filter, update);
        }

        public List<FisaConsum> GetAllConsum(string connectionString, string _databaseName, string _collectionName)
        {
            var client = new MongoClient(connectionString);
            IMongoDatabase _database = client.GetDatabase(_databaseName);
            var collection = _database.GetCollection<BsonDocument>(_collectionName);

            var documents = collection.Find(new BsonDocument()).ToList();
            var productList = new List<FisaConsum>();

            foreach (var document in documents)
            {
                var product = new FisaConsum
                {
                    _id = document["_id"].ToString(),
                    Nume_Produs = document["Nume_Produs"].ToString(),
                    Nume_Materie_Prima = document["Nume_Materie_Prima"].ToString(),
                    Cantitate = document["Cantitate"].ToInt32()
                };

                productList.Add(product);
            }

            return productList;
        }
    }
}
