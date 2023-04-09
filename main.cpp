#include <iostream>
#include "nlohmann/json.hpp"
#include <fstream>

void out_console (nlohmann::json& movie_record) {
    std::cout << "Movie Name: " << movie_record ["movie_name"] << "\n"
              << "Release Date: " << movie_record ["release_dates"] << "\n"
              << "Country: " << movie_record ["country"] << "\n"
              << "Studio: " << movie_record ["studio"] << "\n"
              << "Production Company: " << movie_record ["production_company"] << "\n"
              << "Music By: " << movie_record ["music_by"] << "\n"
              << "Authors: " << movie_record ["authors"] << "\n"
              << "Director: " << movie_record ["director"] << "\n"
              << "Producers: " << movie_record ["producers"] << "\n"
              << "Actors: " << movie_record ["actors"] << std::endl;
}

int main() {
    std::cout << "JSON description of the movie \"Dune\" - directed by Denis Villeneuve. " << std::endl;
    std::cout << "Based on Dune by Frank Herbert" << std::endl;
    std::cout << "Described by Roman Chirkov" << std::endl;
    std::cout << "Check out my JSON file (movie.json)" << std::endl;

    std::ofstream file("movie.json");

    /* The question is - why so hard down there?
    nlohmann::json movie_record = "{ \"movie_name\": \"Dune\", "
                          " \"release_dates\": \"September 3, 2021 (Venice). October 22, 2021 (United States)\","
                          " \"country\": \"United States\","
                          " \"studio\": \"Legendary Pictures\","
                          " \"production_company\": \"Warner Bros Pictures\","
                          " \"music_by\": \"Hans Zimmer\","
                          " \"authors\": \"Frank Herbert, Denis Villeneuve\", "
                          " \"director\": \"Denis Villeneuve\","
                          " \"producers\": \"Denis Villeneuve, Mary Parent, Adam Godman\", "
                          " \"actors\": { "
                          " \"Timothee Chalamet\": \" Paul Atreides\", "
                          " \"Zendaya\": \" Chani\", "
                          " \"Rebecca Ferguson\": \" Lady Jessica\", "
                          " \"Oscar Isaac\": \" Duke Leto Atreides\", "
                          " \"Jason Momoa\": \" Duncan Idaho\", "
                          " \"Stellan Skarsgard\": \" Baron Vladimir Harkonnen\", "
                          " \"Javier Bardem\": \" Stilgar\"}}"_json;
    */

    //is it better by this? more readable imho

    nlohmann::json movie_record {
            {"movie_name", "Dune"},
            {"release_dates", "September 3, 2021 (Venice). October 22, 2021 (United States)"},
            {"country", "United States"},
            {"studio", "Legendary Pictures"},
            {"production_company", "Warner Bros Pictures"},
            {"music_by", "Hans Zimmer"},
            {"authors", "Frank Herbert, Denis Villeneuve"},
            {"director", "Denis Villeneuve"},
            {"producers", "Denis Villeneuve, Mary Parent, Adam Godman"},
            {"actors", "Timothee Chalamet : Paul Atreides, "
                       "Zendaya : Chani, "
                       "Rebecca Ferguson : Lady Jessica, "
                       "Oscar Isaac : Duke Leto Atreides, "
                       "Jason Momoa : Duncan Idaho, "
                       "Stellan Skarsgard : Baron Vladimir Harkonnen, "
                       "Javier Bardem : Stilgar"
            }
    };
    file << movie_record;
    file.close();
    out_console (movie_record);
    return 0;
}