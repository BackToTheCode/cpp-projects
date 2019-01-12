#include "shared.h"

class Board
{
  private:
    int m_height{8};
    int m_width{8};
    int m_size;
    vector<Piece> m_pieces;

  public:
    // Default constructor
    Board()
    {
        m_pieces.resize(m_height * m_width);
        m_size = m_height * m_width;
    }

    void initBoard()
    {
        cout << "\n"
             << endl;
        cout << "=============================================================" << endl;
        cout << "\n"
             << endl;
        cout << "     ______  __    __   _______       _______.   _______. " << endl;
        cout << "    /      ||  |  |  | |   ____|     /       |  /       |" << endl;
        cout << "   |  ,----'|  |__|  | |  |__       |   (----` |   (----`" << endl;
        cout << "   |  |     |   __   | |   __|       \\   \\      \\   \\    " << endl;
        cout << "   |  `----.|  |  |  | |  |____  .----)   | .----)   |   " << endl;
        cout << "    \\______||__|  |__| |_______| |_______/  |_______/    " << endl;
        cout << "\n"
             << endl;
        cout << "============ Welcome to Chess - by James Tuckett ============" << endl;
        cout << "\n"
             << endl;
        cout << "  White Team = CAPITALS" << endl;

        int cells = m_height * m_width;

        // BLACK TEAM
        Piece rook_b{PieceType::ROOK, Freedom::CROSS, Team::BLACK};
        Piece knight_b{PieceType::KNIGHT, Freedom::HOOK, Team::BLACK};
        Piece bishop_b{PieceType::BISHOP, Freedom::DIAGONAL, Team::BLACK};
        Piece queen_b{PieceType::QUEEN, Freedom::DIAGONAL, Team::BLACK};
        Piece king_b{PieceType::KING, Freedom::DIAGONAL, Team::BLACK};

        m_pieces.at(0) = rook_b;
        m_pieces.at(1) = knight_b;
        m_pieces.at(2) = bishop_b;
        m_pieces.at(3) = queen_b;
        m_pieces.at(4) = king_b;
        m_pieces.at(5) = bishop_b;
        m_pieces.at(6) = knight_b;
        m_pieces.at(7) = rook_b;

        for (int i = m_width; i < 2 * m_width; i++)
        {
            Piece pawn{PieceType::PAWN, Freedom::FULL, Team::BLACK};
            m_pieces.at(i) = pawn;
        }

        for (int i = m_width * (m_height - 2); i < cells; i++)
        {
            Piece blankPiece;
            m_pieces.push_back(blankPiece);
        }

        // WHITE TEAM
        for (int i = m_width * (m_height - 2); i < m_size; i++)
        {
            Piece pawn{PieceType::PAWN, Freedom::FULL, Team::WHITE};
            m_pieces.at(i) = pawn;
        }

        Piece rook_w{PieceType::ROOK, Freedom::CROSS, Team::WHITE};
        Piece knight_w{PieceType::KNIGHT, Freedom::HOOK, Team::WHITE};
        Piece bishop_w{PieceType::BISHOP, Freedom::DIAGONAL, Team::WHITE};
        Piece queen_w{PieceType::QUEEN, Freedom::DIAGONAL, Team::WHITE};
        Piece king_w{PieceType::KING, Freedom::DIAGONAL, Team::WHITE};

        m_pieces.at(m_size - 1) = rook_w;
        m_pieces.at(m_size - 2) = knight_w;
        m_pieces.at(m_size - 3) = bishop_w;
        m_pieces.at(m_size - 4) = queen_w;
        m_pieces.at(m_size - 5) = king_w;
        m_pieces.at(m_size - 6) = bishop_w;
        m_pieces.at(m_size - 7) = knight_w;
        m_pieces.at(m_size - 8) = rook_w;
    }

    void printColumnHeaders()
    {
        printLeftMargin();

        cout << "\x1b[31m";
        const char* headers[8] = {"a","b","c","d","e","f","h","g"};
        for (int i = 0; i < m_width; i++)
        {
            cout << "   " << headers[i] << "   ";
        }

        cout << "\x1b[0m";
    }

    void printRowHeader(int rowCount)
    {
        cout << "\x1b[31m";
        cout << "   ";
        cout << (rowCount + 1);
        cout << "\x1b[0m";
    }

    void printLeftMargin()
    {
        // Left margin for Chess board
        cout << "  ";
    }

    void printRows(bool printIcon = true, int rowCount = 0)
    {

        int rowCountComparable = rowCount % 2;
        
        int index = 0;

        printLeftMargin();

        for (int i = 0; i < m_width; i++)
        {
            
            if (i % 2 == rowCountComparable)
            {
                cout << "\x1b[30;47m";
            }
            else
            {
                cout << "\x1b[37;40m";
            }

            if (printIcon && i < m_width)
            {
                index = i + (rowCount * m_width);

                cout << "   " << m_pieces.at(index).getPieceType() << "   ";
            }
            else
            {
                cout << "   "
                     << "    ";
            }
        }

        cout << "\x1b[0m"; 

        if (printIcon)
            printRowHeader(rowCount);
    }

    void printBoard()
    {
        cout << "\n";
        printColumnHeaders();
        cout << "\n";

        for (int j = 0; j < m_height; j++)
        {
            cout << "\n";
            printRows(false, j);
            cout << "\n";
            printRows(true, j);
            cout << "\n";
            printRows(false, j);
        }

        cout << "\n";
        cout << "\n";
        cout << "\n";
    }
};
