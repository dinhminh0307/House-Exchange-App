//
// Created by Vo Nguyen Kien on 09/01/2023.
//

#include "Review.h"
Review::Review(double ratingScore, std::string comment, Member *memberReview) {
    this->ratingScore = ratingScore;
    this->comment = comment;
    this->memberReview = memberReview;

}