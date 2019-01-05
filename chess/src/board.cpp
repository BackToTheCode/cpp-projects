#include "shared.h"


// class Piece;

class Board
{
  private:
    int m_height { 8 };
    int m_width { 8 };
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
        cout << "=============================================================" << endl;
        cout << "\n" << endl;
        cout << "     ______  __    __   _______       _______.   _______. " << endl;
        cout << "    /      ||  |  |  | |   ____|     /       |  /       |" << endl;
        cout << "   |  ,----'|  |__|  | |  |__       |   (----` |   (----`" << endl;
        cout << "   |  |     |   __   | |   __|       \\   \\      \\   \\    " << endl;
        cout << "   |  `----.|  |  |  | |  |____  .----)   | .----)   |   " << endl;
        cout << "    \\______||__|  |__| |_______| |_______/  |_______/    " << endl;
        cout << "\n" << endl;
        cout << "============ Welcome to Chess - by James Tuckett ============" << endl;                                            
        cout << "\n" << endl;
        
        int cells = m_height * m_width;

        // BLACK TEAM
        Piece rook_b {PieceType::ROOK, Freedom::CROSS, Team::BLACK};
        Piece knight_b {PieceType::KNIGHT, Freedom::HOOK, Team::BLACK};
        Piece bishop_b {PieceType::BISHOP, Freedom::DIAGONAL, Team::BLACK};
        Piece queen_b {PieceType::QUEEN, Freedom::DIAGONAL, Team::BLACK};
        Piece king_b {PieceType::KING, Freedom::DIAGONAL, Team::BLACK};

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
            Piece pawn {PieceType::PAWN, Freedom::FULL, Team::BLACK};
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
            Piece pawn {PieceType::PAWN, Freedom::FULL, Team::WHITE};
            m_pieces.at(i) = pawn;
        }

        Piece rook_w {PieceType::ROOK, Freedom::CROSS, Team::WHITE};
        Piece knight_w {PieceType::KNIGHT, Freedom::HOOK, Team::WHITE};
        Piece bishop_w {PieceType::BISHOP, Freedom::DIAGONAL, Team::WHITE};
        Piece queen_w {PieceType::QUEEN, Freedom::DIAGONAL, Team::WHITE};
        Piece king_w {PieceType::KING, Freedom::DIAGONAL, Team::WHITE};

        m_pieces.at(m_size - 1) = rook_w;
        m_pieces.at(m_size - 2) = knight_w;
        m_pieces.at(m_size - 3) = bishop_w;
        m_pieces.at(m_size - 4) = queen_w;
        m_pieces.at(m_size - 5) = king_w;
        m_pieces.at(m_size - 6) = bishop_w;
        m_pieces.at(m_size - 7) = knight_w;
        m_pieces.at(m_size - 8) = rook_w;


    }

    void printRows(bool printIcon = true, int rowCount = 0) 
    {
        int index = 0;
  
        for (int i = 0; i < m_width; i++)
        {

            if (printIcon && i < m_width) {
                index = i + (rowCount * m_width);
                cout << "\x1b[30;47m| " << m_pieces.at(index).getPieceType() << m_pieces.at(index).getTeam() << " ";
                
            } else {
                cout << "|  " << "    ";
            }   

            if (i == m_width - 1) 
            {
                cout << "|";
            }
        }
    }

    void printBoard() 
    { 
        for (int j = 0; j < m_height; j++) 
        {
            for (int i = 0; i < m_width; i++)
            {
                cout << " ------";
            }
            cout << "\n";
            printRows(true, j);
            cout << "\n";
            printRows(false, j);
            cout << "\n";
        }   

        for (int i = 0; i < m_width; i++)
        {
            cout << " ------";
        }  
    }
};
