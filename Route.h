/**
 * @file Route.h
 *
 * @author DHREV
 */
#pragma once

class Route
{
    private:
        unsigned int startID;
        unsigned int endID;
        long double dist_;

    public:
        Route(unsigned start, unsigned end, long double dist);

        unsigned getStartID() const;
        unsigned getEndID() const;
        long double getDist() const;

        void setStartID(unsigned start);
        void setEndID(unsigned end);
        void setDist(long double dist);
};